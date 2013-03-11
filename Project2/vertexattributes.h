#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//class VertexAttributes
//{
//public:
//	VertexAttributes();
//	VertexAttributes(const glm::vec3 & p, const glm::vec3 & c, const glm::vec3 & n, const glm::vec2 & t);
//	VertexAttributes(const VertexAttributes & other);
//	glm::vec3 position;
//	glm::vec3 color;
//	glm::vec3 normal;
//	glm::vec2 texture_coordinate;
//};

class VertexAttributesPCNT
{
public:
        VertexAttributesPCNT();
        VertexAttributesPCNT(const glm::vec3 & p, const glm::vec3 & c, const glm::vec3 & n, const glm::vec2 & t);
        VertexAttributesPCNT(const VertexAttributesPCNT & other);
        glm::vec3 position;
        glm::vec3 color;
        glm::vec3 normal;
        glm::vec2 texture_coordinate;
};

class VertexAttributesPCN
{
public:
        VertexAttributesPCN();
        VertexAttributesPCN(const glm::vec3 & p, const glm::vec3 & c, const glm::vec3 & n);
        VertexAttributesPCN(const VertexAttributesPCN & other);
        glm::vec3 position;
        glm::vec3 color;
        glm::vec3 normal;
};

class VertexAttributesPN
{
public:
        VertexAttributesPN();
        VertexAttributesPN(const glm::vec3 & p, const glm::vec3 & n);
        VertexAttributesPN(const VertexAttributesPN & other);
        glm::vec3 position;
        glm::vec3 normal;
};

class VertexAttributesP
{
public:
        VertexAttributesP();
        VertexAttributesP(const glm::vec3 & p);
        VertexAttributesP(const VertexAttributesP & other);
        glm::vec3 position;
};