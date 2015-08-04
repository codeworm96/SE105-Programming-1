#include "Graph.h"
#include "Point.h"
#include "bin_tree.h"
#include "arrow.h"
#include <stdexcept>

namespace Graph_lib
{
	Binary_tree::Tree_node* Binary_tree::build_tree(int level_left, Point lb_node, int level_height, int gap, int id)
	{
		if (level_left){
			Tree_node* pt = new Tree_node;
			if (level_left > 1){
				//build two subtrees
				//note: id is calculated via passing argument
				pt->lchild = build_tree(level_left - 1, lb_node, level_height, gap, id * 2);
				pt->rchild = build_tree(level_left - 1, lb_node, level_height, gap, id * 2 + 1);
				//calculate position
				Point lc = pt->lchild->pos;
				Point rc = pt->rchild->pos;
				Point center((lc.x + rc.x) / 2, lc.y - level_height);
				pt->pos = center;
			}
			else{
				//last level: only a circle
				pt->pos = Point(lb_node.x + id * gap, lb_node.y);
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
			draw_a_node(p->pos, sz);
			//label
			Text text(Point(p->pos.x + sz, p->pos.y), p->label);
			text.draw();
			//draw two subtree;
			draw_node(p->lchild);
			draw_node(p->rchild);
		}
	}

	void Binary_tree::draw_links(Tree_node* p) const
	{
		if (p){
			//draw two subtree;
			if (p->lchild){
				(*draw_a_line)(p->pos, p->lchild->pos);
				draw_links(p->lchild);
			}
			if (p->rchild){
				(*draw_a_line)(p->pos, p->rchild->pos);
				draw_links(p->rchild);
			}
		}
	}

	void Binary_tree::dispose(Tree_node* p)
	{
		if (p){
			//dispose two subtree
			dispose(p->lchild);
			dispose(p->rchild);
			//dispose self
			delete p;
		}
	}

	Binary_tree::Binary_tree(int levels, Point lb_node, int size, int level_height, int gap, Line_drawer* ld)
		:draw_a_line(ld)
	{
		//check
		if (size < 0 || level_height < 0 || gap < 0 || levels < 0){
			throw std::runtime_error("Binary_tree: invalid argument");
		}

		sz = size;
		root = build_tree(levels, lb_node, level_height, gap, 0);
	}

	Binary_tree::Binary_tree(Point lt_node, int levels, int width, int height, int size, Line_drawer* ld)
		:draw_a_line(ld)
	{
		//check
		if (size < 0 || levels < 0 || width < 0 || height < 0){
			throw std::runtime_error("Binary_tree: invalid argument");
		}

		sz = size;

		if (levels > 1){//more than one
			Point lb_node(lt_node.x + size, lt_node.y + height - size);
			//calc 2^(levels-1)
			int cnt = 1;
			for (int i = 1; i < levels; ++i){
				cnt *= 2;
			}

			root = build_tree(levels, lb_node, (height - 2 * size) / (levels - 1), (width - 2 * size) / (cnt - 1), 0);
		}
		else{
			if (levels){//1
				Point lb_node(lt_node.x + width / 2, lt_node.y + height / 2);//put in the centre
				root = build_tree(levels, lb_node, 0, 0, 0);
			}
			else{//0
				root = nullptr;
			}
		}
	}

	void Binary_tree::draw_lines() const
	{
		draw_links(root);//draw line;
		draw_node(root);//draw the nodes
	}

	Binary_tree::~Binary_tree()
	{
		dispose(root);//deletes
	}

	void Binary_tree::draw_a_node(Point p, int size) const //draw a circle
	{
		Circle c(p, size);
		c.set_color(color());
		c.set_fill_color(fill_color());
		c.draw();
	}

	void Binary_tree::set_node_label(Tree_node* p, const string& path, const string& text)
	{
		if (p){
			if (path == ""){//reached
				p->label = text;
			}
			else{
				if (path[0] == 'l'){
					set_node_label(p->lchild, path.substr(1, string::npos), text);
				}
				else{
					if (path[0] == 'r'){
						set_node_label(p->rchild, path.substr(1, string::npos), text);
					}
					else{
						throw std::runtime_error("invalid path");
					}
				}
			}
		}
		else{
			throw std::runtime_error("invalid path");
		}
	}

	void Binary_tree::set_label(const string& path, const string text)
	{
		set_node_label(root, path, text);
	}

	//The binary tree with triangle node

	void Tri_binary_tree::draw_a_node(Point p, int size) const
	{
		Regular_triangle c(p, size);
		c.set_color(color());
		c.set_fill_color(fill_color());
		c.draw();
	}

	//line styles

	void Normal_line::operator() (Point p1, Point p2) const
	{
		Line l(p1, p2);
		l.draw();
	}

	void Arrow_line::operator() (Point p1, Point p2) const
	{
		Arrow a(p1, p2);
		a.draw();
	}

	void Red_arrow_line::operator() (Point p1, Point p2) const
	{
		Arrow a(p1, p2);
		a.set_color(Color::red);
		a.draw();
	}
}