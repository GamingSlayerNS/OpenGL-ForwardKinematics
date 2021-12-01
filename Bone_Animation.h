#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	

class Bone_Animation
{
public:
	Bone_Animation();
	~Bone_Animation();

	void init();
	void update(float delta_time);
	glm::mat4 bone1_matrix(glm::mat4 bone1_mat);
	glm::mat4 bone2_matrix(glm::mat4 bone2_mat);
	glm::mat4 bone3_matrix(glm::mat4 bone3_mat);
	void reset();

public:

	// Here the head of each vector is the root bone
	std::vector<glm::vec3> scale_vector;
	std::vector<glm::vec3> rotation_degree_vector;
	std::vector<glm::vec4> colors;
	std::vector<glm::mat4> rotate_matrix;

	glm::vec3 root_position;
	glm::vec3 bone1_position;
	glm::vec3 bone2_position;
	glm::vec3 bone3_position;
};

