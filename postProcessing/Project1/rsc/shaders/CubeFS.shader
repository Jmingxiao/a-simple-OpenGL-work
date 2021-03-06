#version 330 core

out vec4 color;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


in vec3 oNormal;
in vec3 FragPos;
in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.ambient;

    // diffuse 
    vec3 norm = normalize(oNormal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec4 texColor = texture(u_Texture, v_TexCoord);
    float average = 0.2126 * texColor.r + 0.7152 * texColor.g +0.0722 * texColor.b;
    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0) * texColor;
    //color = vec4(result, 1.0) * vec4(average, average, average, 1.0);

};
