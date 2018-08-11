#ifndef IndexBuffer_H
#define IndexBuffer_H

class IndexBuffer 
{
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void UnBind() const;

    inline unsigned int GetCount() const { return _count; };

private:
    unsigned int    _rendererID;
    unsigned int    _count;
};

#endif // IndexBuffer_H