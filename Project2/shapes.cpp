#include "shapes.h"

// Stores the vertex indeces that define the triangles in any shape
// height and width refer to the number of vertices in the object as it wraps around.
// startPos is the position of the first vertex for a shape in the vertex array
void DefineVertexIndices(vector<GLuint> & vertex_indices, int cols, int rows, int startPos)
{
	int end = startPos + rows*(cols-1);

	// Using CW winding and assuming that vertices are in row-major order
	for (int i = startPos; i < end; i++)
	{
		// Add a triangle if the vertex isn't the last in a row
		if (i%rows != rows-1)
		{
			vertex_indices.push_back(i);
			vertex_indices.push_back(i+1);
			vertex_indices.push_back(i+rows);
		}
		// Add a triangle if the vertex isn't the first in a row
		if (i%rows != 0)
		{
			vertex_indices.push_back(i);
			vertex_indices.push_back(i+rows);
			vertex_indices.push_back(i+rows-1);
		}
	}
}

//void DefineRectangle(vector<VertexAttributes> & vertices, vector<GLuint> & vertex_indices, vec3 topleft, int height, int width)
//{
//	vec3 p = topleft;
//	vec3 c = vec3(1.0f, 0.0f, 0.0f);
//	vec3 n = vec3(0.0f, 0.0f, 1.0f);
//	vec2 t = vec2(0.0f, 0.0f);
//
//	for (int i = 0; i < height; i++)
//	{
//		p.x = p.x - i;
//		p.y = topleft.y;
//		for (int j = 0; j < width; j++)
//		{
//			p.y = p.y + j;
//			vertices.push_back(VertexAttributes(p, c, n, t));
//		}
//	}
//
//	// Vertex indices to create the triangles
//	vertex_indices.push_back(0);
//	vertex_indices.push_back(1);
//	vertex_indices.push_back(2);
//	vertex_indices.push_back(1);
//	vertex_indices.push_back(3);
//	vertex_indices.push_back(2);
//}
//
//void DefineCube(vector<VertexAttributes> & vertices, vector<GLuint> & vertex_indices, vec3 center, int height, int width)
//{
//	//DefineRhombus(vertices, vertex_indices, center, height, width, 0.0f);
//
//	//// Each vertex attribute is composed of geometry, color, normal and texture coordinate
//	//vertices.push_back(VertexAttributes(vec3(-1.0f, 1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)));
//	//vertices.push_back(VertexAttributes(vec3(1.0f, 1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)));
//	//vertices.push_back(VertexAttributes(vec3(1.0f, -1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)));
//	//vertices.push_back(VertexAttributes(vec3(-1.0f, -1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)));
//
//	//// Vertex indices to create the triangles
//	//vertex_indices.push_back(0);
//	//vertex_indices.push_back(1);
//	//vertex_indices.push_back(3);
//	//vertex_indices.push_back(1);
//	//vertex_indices.push_back(2);
//	//vertex_indices.push_back(3);
//}

void DefineRhombus(vector<VertexAttributes> & vertices, vector<GLuint> & vertex_indices, vec3 topleft, vec3 up, vec3 right, float height, float width, float angle, int vertexRows, int vertexCols)
{
	// Indicates where this shape starts in the vertex array
	int startPos = vertices.size();

	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vertices.push_back(VertexAttributes(p, c, n, t));
			p.x = p.x + 1;
		}
		p.y = p.y - 1;
		p.x = p.x - width - tanf(angle);
	}*/

	vec3 up_n = glm::normalize(up);
	vec3 right_n = glm::normalize(right);

	float vertexRowSpacing = height/vertexRows;
	float vertexColSpacing = width/vertexCols;

	// Vertex attributes
	vec3 p = topleft;
	vec3 n = cross(right_n, up_n);
	vec3 c(1.0f, 0.0f, 0.0f);
	vec2 t(0.0f, 0.0f);

	/*for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			vertices.push_back(VertexAttributes(p, c, n, t));
			p = p + right_n;
		}
		p = p - up_n;
		p = p - (right_n * (float(width+1) - tanf(angle)));
	}*/

	for (int i = 0; i < vertexRows; i++)
	{
		for (int j = 0; j < vertexCols; j++)
		{
			vertices.push_back(VertexAttributes(p, c, n, t));
			p = p + right_n * vertexColSpacing;
		}
		p = p - up_n * vertexRowSpacing;
		//p = p - (right_n * (width - tanf(angle)));
		p = p - (right_n * width) + (right_n * tanf(angle));
	}

	DefineVertexIndices(vertex_indices, vertexRows, vertexCols, startPos);
}