#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std; 
int MYMESH_INDEX = 0;
const string names[] = { "box.obj", "sphere.obj", "teapot.obj" };

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;

		Mesh* second_mesh = new Mesh("sample_mesh");
		second_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[second_mesh->GetMeshID()] = second_mesh;

		// objects to loop through
		Mesh* mymesh = new Mesh("mymesh");
		mymesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mymesh->GetMeshID()] = mymesh;
	}
}

void Laborator1::FrameStart()
{

}

void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer
	glClearColor(0, 0, 0, 1);

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// render the object
	RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

	// render the object again but with different properties
	RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));

	// render 3rd object
	RenderMesh(meshes["sample_mesh"], glm::vec3(-1, -2, -1));

	// render 4th object (the one that is looped through)
	RenderMesh(meshes["mymesh"], glm::vec3(1, 4, 1));
}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input
};

void Laborator1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_F) {
		glClearColor(0, 0, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		Mesh* new_mesh = new Mesh("mymesh");
		new_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", names[MYMESH_INDEX]);
		meshes["mymesh"]->ClearData();
		free(meshes["mymesh"]);
		meshes["mymesh"] = new_mesh;
		MYMESH_INDEX = (MYMESH_INDEX + 1) % 3;
	}
	if (key == GLFW_KEY_W) {

	}
	if (key == GLFW_KEY_A) {

	}
	if (key == GLFW_KEY_S) {

	}
	if (key == GLFW_KEY_D) {

	}
	if (key == GLFW_KEY_Q) {

	}
	if (key == GLFW_KEY_E) {

	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
