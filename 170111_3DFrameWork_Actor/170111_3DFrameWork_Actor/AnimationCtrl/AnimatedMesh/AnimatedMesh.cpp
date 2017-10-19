#include "AnimatedMesh.h"

AnimatedMesh::AnimatedMesh(GSuint mesh, GSuint skeleton, GSuint animation, GSuint motion)
	:mesh_{ mesh }, skeleton_{ skeleton }, animation_{ animation,motion }
{
}

void AnimatedMesh::update(float delta_time)
{
	animation_.update(delta_time);
}

void AnimatedMesh::draw() const
{
	gsDisable(GS_CALC_SKELETON);
	gsEnable(GS_SKIN_MESH);
	gsBindSkeleton(skeleton_);
	gsSetMatrixSkeleton(matrices_.data());
	gsDrawMesh(mesh_);
}

void AnimatedMesh::change_motion(GSuint moiton)
{
	animation_.change_motion(moiton);
}

void AnimatedMesh::transform(const GSmatrix4 & matrix)
{
	gsBindSkeleton(skeleton_);
	gsCalculateSkeleton(&matrix, animation_.get_bone_matrices().data(), matrices_.data());
}

float AnimatedMesh::motion_end_time() const
{
	return animation_.end_time();
}

GSmatrix4 AnimatedMesh::get_bone_matrix(int bone_no) const
{
	return matrices_.at(bone_no);
}
