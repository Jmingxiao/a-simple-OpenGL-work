#pragma once

#include<string>
#include<unordered_map>

#include"glm/glm.hpp"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	//caching for uniforms
public:
	unsigned int ID;
	Shader();
	Shader(const std::string& filepath);
	~Shader();
	void Creat(const std::string& filepath);
	void Bind()const;
	void Unbind() const;
	//ser uniforms
	void SetUniform1iv(const std::string& name, int count, int* value);
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform4f(const std::string& name,float v0, float v1,float v2,float v3 );
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CreatShaders(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};