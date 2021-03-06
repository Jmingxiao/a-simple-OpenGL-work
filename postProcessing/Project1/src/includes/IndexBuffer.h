
#pragma once
class IndexBuffer
{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IndexBuffer();
	~IndexBuffer();

	void Creat(const unsigned int* data, unsigned int count);
	void DynamicDraw(const void* data, unsigned int count);
	void Subdata(const void* data, unsigned int count);
	void Bind()const;
	void Unbind()const;

	inline unsigned int Getcount() const { return m_Count; }
};