#include "Graph.h"
#include "Point.h"
#include "bin_tree.h"
#include <stdexcept>

namespace Graph_lib
{
	Binary_tree::Tree_node* Binary_tree::build_tree(int level_left, Point lb_node, int size, int level_height, int gap, int id)
	{
		if (level_left){
			Tree_node* pt = new Tree_node;
			if (level_left > 1){
				//build two subtrees
				//note: id is calculated via passing argument
				pt->lchild = build_tree(level_left - 1, lb_node, size, level_height, gap, id * 2);
				pt->rchild = build_tree(level_left - 1, lb_node, size, level_height, gap, id * 2 + 1);

				Point lc = pt->lchild->cir->center();
				Point rc = pt->rchild->cir->center();
				Point center((lc.x + rc.x) / 2, lc.y - level_height);
				pt->cir = new Circle(center, size);//the circle
				//two lines
				skeleton.add(lc, center);
				skeleton.add(rc, center);
			}
			else{
				//last level: only a circle
				pt->cir = new Circle(Point(lb_node.x + id * gap, lb_node.y), size);
			}
			return pt;
		}
		else{
			return nullptr;
		}
	}

	void Binary_tree::draw_node(Tree_node* p) const
	{
		if (p){
			//draw self
			p->cir->draw();
			//draw two subtree;
			draw_node(p->lchild);
			draw_node(p->rchild);
		}
	}

	void Binary_tree::dispose(Tree_node* p)
	{
		if (p){
			//dispose two subtree
			dispose(p->lchild);
			dispose(p->rchild);
			//dispose self
			delete p->cir;
			delete p;
		}
	}

	Binary_tree::Binary_tree(int levels, Point lb_node, int size, int level_height, int gap)
	{
		//check
		if (size < 0 || level_height < 0 || gap < 0 || levels < 0){
			throw std::runtime_error("Binary_tree: invalid argument");
		}

		root = build_tree(levels, lb_node, size, level_height, gap, 0);
	}

	Binary_tree::Binary_tree(Point lt_node, int levels, int width, int height, int size)
	{
		//check
		if (size < 0 || levels < 0 || width < 0 || height < 0){
			throw std::runtime_error("Binary_tree: invalid argument");
		}

		if (levels > 1){//more than one
			Point lb_node(lt_node.x + size, lt_node.y + height - size);
			//calc 2^(levels-1)
			int cnt = 1;
			for (int i = 1; i < levels; ++i){
				cnt *= 2;
			}

			root = build_tree(levels, lb_node, size, (height - 2 * size) / (levels - 1), (width - 2 * size) / (cnt - 1), 0);
		}
		else{
			if (levels){//1
				Point lb_node(lt_node.x + width / 2, lt_node.y + height / 2);//put in the centre
				root = build_tree(levels, lb_node, size, 0, 0, 0);
			}
			else{//0
				root = nullptr;
			}
		}
	}

	void Binary_tree::draw_lines() const
	{
		skeleton.draw();//draw the lines
		draw_node(root);//draw the circles
	}

	Binary_tree::~Binary_tree()
	{
		dispose(root);//deletes
	}
}