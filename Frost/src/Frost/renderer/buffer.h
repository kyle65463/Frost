#pragma once

namespace Frost
{
    enum class ShaderDataType
    {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool,
    };

    static uint32_t shaderDataTypeSize(ShaderDataType type)
    {
        switch(type)
        {
            case ShaderDataType::Float: return 4;
            case ShaderDataType::Float2: return 4 * 2;
            case ShaderDataType::Float3: return 4 * 3;
            case ShaderDataType::Float4: return 4 * 4;
            case ShaderDataType::Mat3: return 4 * 3 * 3;
            case ShaderDataType::Mat4: return 4 * 4 * 4;
            case ShaderDataType::Int: return 4;
            case ShaderDataType::Int2: return 4 * 2;
            case ShaderDataType::Int3: return 4 * 3;
            case ShaderDataType::Int4: return 4 * 4;
            case ShaderDataType::Bool: return 1;
        }
        FS_CORE_ERROR("Unknown shader data type");
        return 0;
    }

    struct BufferElement
    {
        BufferElement() {}
        BufferElement(ShaderDataType type, const std::string &name, bool normalized = false)
            : name(name), type(type), size(shaderDataTypeSize(type)), offset(0), normalized(normalized)
        {
        }

        std::string name;
        ShaderDataType type;
        uint32_t offset;
        uint32_t size;
        bool normalized;

		uint32_t getComponentCount() const
		{
			switch (type)
			{
				case ShaderDataType::Float:   return 1;
				case ShaderDataType::Float2:  return 2;
				case ShaderDataType::Float3:  return 3;
				case ShaderDataType::Float4:  return 4;
				case ShaderDataType::Mat3:    return 3 * 3;
				case ShaderDataType::Mat4:    return 4 * 4;
				case ShaderDataType::Int:     return 1;
				case ShaderDataType::Int2:    return 2;
				case ShaderDataType::Int3:    return 3;
				case ShaderDataType::Int4:    return 4;
				case ShaderDataType::Bool:    return 1;
			}

			FS_CORE_ERROR("Unknown shader data type");
			return 0;
		}
    };

    class BufferLayout
    {
        public:
            BufferLayout() {}

            BufferLayout(const std::initializer_list<BufferElement>& elements)
            : elements(elements)
            {
                calculateOffsetsAndStride();
            }
            
            inline uint32_t getStride() const { return stride; }
            inline const std::vector<BufferElement> &getElements() const { return elements; }
            std::vector<BufferElement>::iterator begin() { return elements.begin(); }
            std::vector<BufferElement>::iterator end() { return elements.end(); }
            std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
            std::vector<BufferElement>::const_iterator end() const { return elements.end(); }

        private:
            std::vector<BufferElement> elements;
            uint32_t stride;

            void calculateOffsetsAndStride()
            {
                uint32_t offset = 0;
                stride = 0;
                for (auto& element: elements)
                {
                    element.offset = offset;
                    offset += element.size;
                    stride += element.size;
                }
            }
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual const BufferLayout& getLayout() const = 0;
        virtual void setLayout(const BufferLayout& layout) = 0;

        static VertexBuffer *create(float *vertices, uint32_t size);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual uint32_t getCount() const = 0;

        static IndexBuffer *create(uint32_t *indices, uint32_t size);
    };
}