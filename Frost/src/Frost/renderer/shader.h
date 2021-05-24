#pragma once

#include <string>

namespace Frost
{
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
        
        void bind() const;
        void unbind() const;

    private:
        unsigned int rendererId;
    };
}