#include "Maze.hpp"

//���H�̉���
constexpr size_t size_x = 41;
//���H�̏c��
constexpr size_t size_y = 21;

//���H�ɐݒu���镨�̂�ID
enum :size_t {
	id_empty_,//�ʘH
	id_wall_,//��
	id_root_,//�S�[���܂ł̓�
};

int main()
{
	//���H����
	return maze::createMaze(size_x, size_y, id_empty_, id_wall_, id_root_);
}

