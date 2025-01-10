#include "Maze.hpp"

//–À˜H‚Ì‰¡•
constexpr size_t size_x = 41;
//–À˜H‚Ìc•
constexpr size_t size_y = 21;

//–À˜H‚Éİ’u‚·‚é•¨‘Ì‚ÌID
enum :size_t {
	id_empty_,//’Ê˜H
	id_wall_,//•Ç
	id_root_,//ƒS[ƒ‹‚Ü‚Å‚Ì“¹
};

int main()
{
	//–À˜H¶¬
	return maze::createMaze(size_x, size_y, id_empty_, id_wall_, id_root_);
}

