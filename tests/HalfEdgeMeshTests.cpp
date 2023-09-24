#include <gtest/gtest.h>
#include "Meshes/HalfEdgeMesh.h"
#include <unistd.h>
#include <filesystem>

TEST(HalfEdgeMeshTests, ReadFromFile)
{
	HalfEdgeMesh hem = HalfEdgeMesh("./../../res/obj/teddy.obj");
}