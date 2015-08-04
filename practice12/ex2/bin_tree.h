#include "Graph.h"
#include "Point.h"

namespace Graph_lib
{
	//the abstract class for the object decide the line's style
	struct Line_drawer
	{
		virtual void operator() (Point, Point) const =0;
	};

	//available line styles
	struct Normal_line :public Line_drawer
	{
		void operator() (Point, Point) const;
	};

	struct Arrow_line :public Line_drawer
	{
		void operator() (Point, Point) const;
	};

	struct Red_arrow_line :public Line_drawer
	{
		void operator() (Point, Point) const;
	};

	//The binary tree

	class Binary_tree :public Shape
	{
	public:
		//constructor:fit to an area
		//lt_node: left-top point
		//size: size of the circle
		//ld: style of the line links two nodes
		Binary_tree(Point lt_node, int levels, int width, int height, int size = 10, Line_drawer* ld = &Normal_line());
		//constructor:lb_node: lb_node:left_botton circle's centre,level_height : gap between two levels,
	    //gap: gap between two node in the last level
		//ld: style of the line links two nodes
		Binary_tree(int levels, Point lb_node, int size = 10, int level_height = 70, int gap = 30, Line_drawer* ld = &Normal_line());
		void draw_lines() const;
		//set the label of a node
		//path like lrrl
		//if path is invalid, throws
		void set_label(const string& path, const string text);
		~Binary_tree();//destructor
	private:
		//To restore the tree;
		struct Tree_node
		{
			//two subtree
			Tree_node* lchild;
			Tree_node* rchild;
			//the label
			string label;
			//position
			Point pos;
			//constructor
			Tree_node() :lchild(nullptr), rchild(nullptr), label(""), pos(0, 0){}
		};

		Tree_node* root;//root of the tree
		int sz;//size of node
		Line_drawer* draw_a_line;//funtion object to link the nodes

		//build tree:id means the index of node in the last level
		Tree_node* build_tree(int level_left, Point lb_node, int level_height, int gap, int id);
		//draw all node in the sub-tree;
		void draw_node(Tree_node* p) const;
		//the virtual function for change the shape of a node
		virtual void draw_a_node(Point p, int size) const;

		void draw_links(Tree_node* p) const;

		void set_node_label(Tree_node* p, const string& path, const string& text);
		//dispose all node in the sub-tree;
		void dispose(Tree_node* p);
	};

	class Tri_binary_tree :public Binary_tree
	{
	public:
		//constructor:fit to an area
		//lt_node: left-top point
		//size: size of the circle
		Tri_binary_tree(Point lt_node, int levels, int width, int height, int size = 10, Line_drawer* ld = &Normal_line())
			:Binary_tree(lt_node, levels, width, height, size, ld){}
		//constructor:lb_node: lb_node:left_botton circle's centre,level_height : gap between two levels,
		//gap: gap between two node in the last level
		Tri_binary_tree(int levels, Point lb_node, int size = 10, int level_height = 70, int gap = 30, Line_drawer* ld = &Normal_line())
			:Binary_tree(levels, lb_node, size, level_height, gap, ld){}
	private:
		void draw_a_node(Point p, int size) const;
	};
}