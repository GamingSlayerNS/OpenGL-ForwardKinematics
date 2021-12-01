#include "Bone_Animation.h"



Bone_Animation::Bone_Animation()
{
}


Bone_Animation::~Bone_Animation()
{
}

void Bone_Animation::init()
{
	root_position  = {2.0f, 1.0f, 2.0f};
	bone1_position = {2.0f, 3.5f, 2.0f};
	bone2_position = {2.0f, 7.0f, 2.0f};
	bone3_position = {2.0f, 9.5f, 2.0f};

	scale_vector =
	{
		{1.0f,1.0f,1.0f},
		{0.5f,4.0f,0.5f},
		{0.5f,3.0f,0.5f},
		{0.5f,2.0f,0.5f}
	};

	rotation_degree_vector = 
	{
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f}
	};

	colors = 
	{
		{0.7f,0.0f,0.0f,1.0f},
		{0.37f,0.12f,0.62f,1.0f},
		{0.0f,0.7f,0.7f,1.0f},
		{0.0f,0.7f,0.0f,1.0f}
	};

}

void Bone_Animation::update(float delta_time)
{
	rotate_matrix = std::vector<glm::mat4>();

	//Root Bone
	rotate_matrix.push_back(glm::mat4(1.0f));
	
	//Purple Bone
	glm::mat4 purpleMatrix =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][0]), glm::vec3(1.0, 0.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][1]), glm::vec3(0.0, 1.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[1][2]), glm::vec3(0.0, 0.0, 1.0));
	rotate_matrix.push_back(purpleMatrix);

	//Cyan Bone
	glm::mat4 cyanMatrix =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][0]), glm::vec3(1.0, 0.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][1]), glm::vec3(0.0, 1.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[2][2]), glm::vec3(0.0, 0.0, 1.0));
	rotate_matrix.push_back(cyanMatrix);

	//Green Bone
	glm::mat4 greenMatrix =
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][0]), glm::vec3(1.0, 0.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][1]), glm::vec3(0.0, 1.0, 0.0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(rotation_degree_vector[3][2]), glm::vec3(0.0, 0.0, 1.0));
	rotate_matrix.push_back(greenMatrix);
}

glm::mat4 Bone_Animation::bone1_matrix(glm::mat4 bone1_mat)
{
	bone1_mat =
		glm::translate(bone1_mat, glm::vec3(0.0f, -(scale_vector[1][1] / 2), 0.0f)) *		//move bone origin to bottom of bone from center of bone
		glm::translate(bone1_mat, bone1_position) *											//move bone according to root_position
		rotate_matrix[1] *																	//rotate bone according to rotation_degree_vector
		glm::translate(bone1_mat, glm::vec3(0.0f, scale_vector[1][1] / 2, 0.0f)) *			//move bone origin back to center of bone
		glm::scale(bone1_mat, scale_vector[1]);												//scale bone according to scale_vector
	return bone1_mat;
}

glm::mat4 Bone_Animation::bone2_matrix(glm::mat4 bone2_mat)
{
	bone2_mat = 
		glm::translate(bone2_mat, glm::vec3(0.0f, -(scale_vector[2][1] / 2), 0.0f)) *		//move bone origin to bottom of bone from center of bone
		glm::translate(bone2_mat, glm::vec3(0.0f, -(scale_vector[1][1]), 0.0f)) *				//Apply bone1 -translation
		glm::translate(bone2_mat, bone2_position) *											//move bone according to root_position
		rotate_matrix[1] *																		//Apply bone1 rotation
		glm::translate(bone2_mat, glm::vec3(0.0f, scale_vector[1][1], 0.0f)) *					//Apply bone1 translation
		rotate_matrix[2] *																	//rotate bone according to rotation_degree_vector
		glm::translate(bone2_mat, glm::vec3(0.0f, scale_vector[2][1] / 2, 0.0f)) *			//move bone origin back to center of bone
		glm::scale(bone2_mat, scale_vector[2]);												//scale bone according to scale_vector
	return bone2_mat;
}

glm::mat4 Bone_Animation::bone3_matrix(glm::mat4 bone3_mat)
{
	bone3_mat = 
		glm::translate(bone3_mat, glm::vec3(0.0f, -(scale_vector[3][1] / 2), 0.0f)) *		//move bone origin to bottom of bone from center of bone
		glm::translate(bone3_mat, glm::vec3(0.0f, -(scale_vector[2][1]), 0.0f)) *				//Apply bone2 -translation
		glm::translate(bone3_mat, glm::vec3(0.0f, -(scale_vector[1][1]), 0.0f)) *					//Apply bone1 -translation
		glm::translate(bone3_mat, bone3_position) *											//move bone according to root_position
		rotate_matrix[1] *																			//Apply bone1 rotation
		glm::translate(bone3_mat, glm::vec3(0.0f, scale_vector[1][1], 0.0f)) *						//Apply bone1 translation
		rotate_matrix[2] *																		//Apply bone2 rotation
		glm::translate(bone3_mat, glm::vec3(0.0f, scale_vector[2][1], 0.0f)) *					//Apply bone2 translation
		rotate_matrix[3] *																	//rotate bone according to rotation_degree_vector
		glm::translate(bone3_mat, glm::vec3(0.0f, scale_vector[3][1] / 2, 0.0f)) *			//move bone origin back to center of bone
		glm::scale(bone3_mat, scale_vector[3]);												//scale bone according to scale_vector
	return bone3_mat;
}

void Bone_Animation::reset()
{
}

