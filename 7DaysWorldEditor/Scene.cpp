#include "Scene.h"

#include "Loader.h"

#include "GL\glew.h"

Scene::Scene() {
	/*GLfloat vertices[9] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};*/

	GLfloat vertices[] = {
		-0.5f,0.5f,-0.5f,
                -0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,0.5f,-0.5f,
 
                -0.5f,0.5f,0.5f,
                -0.5f,-0.5f,0.5f,
                0.5f,-0.5f,0.5f,
                0.5f,0.5f,0.5f,
 
                0.5f,0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,0.5f,
                0.5f,0.5f,0.5f,
 
                -0.5f,0.5f,-0.5f,
                -0.5f,-0.5f,-0.5f,
                -0.5f,-0.5f,0.5f,
                -0.5f,0.5f,0.5f,
 
                -0.5f,0.5f,0.5f,
                -0.5f,0.5f,-0.5f,
                0.5f,0.5f,-0.5f,
                0.5f,0.5f,0.5f,
 
                -0.5f,-0.5f,0.5f,
                -0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,-0.5f,
                0.5f,-0.5f,0.5f
	};

	/*static GLfloat vertices[] = {
		// front
		-1.0, -1.0,  1.0,
		1.0, -1.0,  1.0,
		1.0,  1.0,  1.0,
		-1.0,  1.0,  1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0,  1.0, -1.0,
		-1.0,  1.0, -1.0,
	};*/

	int indices[36] = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22

	};

	/**static int indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3,
	};*/

	static float textureCoords[48] = {
	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0,

	  0,0,
	  0,1,
	  1,1,
	  1,0
	};

	GLuint VertexArrayID = 1;
	///glGenVertexArrays(1, &VertexArrayID);
	///glBindVertexArray(VertexArrayID);

	/*static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};*/
	///GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	///glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	///glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	///glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	///glEnableVertexAttribArray(0);
	/*glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);*/
	///glBindBuffer(GL_ARRAY_BUFFER, 0);
	///glBindVertexArray(0);


	loader = Loader();

	Camera camera = Camera(glm::vec3(0.0f), glm::angleAxis(0.0f, glm::vec3(0.0f, 0.0f, 1.0f)), 90.0f, 16.0f / 9.0f, 0.00001f, 10000.0f);

	renderer = Renderer(camera);
	shader = StaticShader();

	Mesh mesh;

	loader.loadToVAO(mesh, vertices, sizeof(vertices) / (3 * sizeof(vertices[0])),
                           indices, sizeof(indices) / sizeof(indices[0]),
		                   textureCoords, sizeof(textureCoords) / (2 * sizeof(textureCoords[0])));

	Texture texture = Texture(loader.loadTexture("texture"));
	TexturedMesh texturedMesh = TexturedMesh(mesh, texture);

	Transformation entityTransformation = Transformation(glm::vec3(0.0f, 0.0f, -20.5f));//, glm::vec3(0.0f), glm::vec3(1.0f));
	entity = Entity(texturedMesh, entityTransformation);
}

Scene::~Scene() {}

void Scene::render() {
	renderer.prepare();
	/*glClearColor(std::sin(c / 1000), std::sin(c / 100), std::sin(c / 10), 1.0f);
	c += 1.0f;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);*/

	///glBindVertexArray(1);
	////glBindBuffer(GL_ARRAY_BUFFER, 1);
	//glEnableVertexAttribArray(0);
	// Draw the triangle !
	///glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	//glDisableVertexAttribArray(0);
	///glBindBuffer(GL_ARRAY_BUFFER, 0);
	///glBindVertexArray(0);

/*
	glBindVertexArray(VertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glEnableVertexAttribArray(0);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);*/
	
	//renderer.prepare();
	shader.start();

	//for (int i = -5; i < 5; i += 2) {
		//for (int j = -5; j < 5; j += 2) {
			//for (int k = -5; k < 5; k += 2) {
				//entity.getEntityTransformation().setPosition(glm::vec3(i, j, k));
				renderer.render(entity, shader);
			//}
		//}
	//}

	/*renderer.render(entity, shader);
	entity.getEntityTransformation().setPosition(glm::vec3(glm::sin(p)*6, glm::cos(p)*5, glm::sin(p/100)));
	p += 0.1;*/

	shader.stop();
}
