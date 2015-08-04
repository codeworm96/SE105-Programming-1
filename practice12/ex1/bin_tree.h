#include "Graph.h"
#include "Point.h"

namespace Graph_lib
{
	class Binary_tree :public Shape
	{
	public:
		//constructor:fit to an area
		//lt_node: left-top point
		//size: size of the circle
		Binary_tree(Point lt_node, int levels, int width, int height, int size = 10);
		//constructor:lb_node: lb_node:left_botton circle's centre,level_height : gap between two levels,
	    //gap: gap between two node in the last level
		Binary_tree(int levels, Point lb_node, int size = 10, int level_height = 70, int gap = 30);
		void draw_lines() const;
		~Binary_tree();
	private:
		//To restore the tree;
		struct Tree_node
		{
			Tree_node* lchild;
			Tree_node* rchild;
			Circle* cir;
			Tree_node():lchild(nullptr), rchild(nullptr), cir(nullptr){}
		};

		Lines skeleton;//lines link two nodes
		Tree_node* root;//root of the tree

		//build tree:id means the index of node in the last level
		Tree_node* build_tree(int level_left, Point lb_node, int size, int level_height, int gap, int id);
		//draw all node in the sub-tree;
		void draw_node(Tree_node* p) const;
		//dispose all node in the sub-tree;
		void dispose(Tree_node* p);
	};
}