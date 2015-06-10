/* Name: Yuge Zhao
 ID: 204202442
 Date: May 29
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "TreeNode.cpp"
#include "Point2D.cpp"

int main() {
    
    //Creat binary search trea, give it value {2,3,5,11,13,17}
    BinarySearchTree<int> bst;
    bst.insert(3); bst.insert(2); bst.insert(11);
    bst.insert(13); bst.insert(5); bst.insert(17);

    
    //Prints to the console: 2,3,5,11,13,17,
    

    /*for(auto x: bst)std::cout << x << ",";
    std::cout << std::endl;*/
   
    //Prints to the console: Copy made
    BinarySearchTree<int> deep_copy(bst);
    
    //Prints to the console: Move performed
    BinarySearchTree<int> move_copy(std::move(bst));
    
    BinarySearchTree<int> default_bst;
    
    //Prints to the console: Copy made
    default_bst = deep_copy;
    
    //Prints to the console: Move performed
    default_bst = std::move(move_copy);
    
    
    BinarySearchTree<Point2D, PointOrderx> points_by_x;
    points_by_x.insert(Point2D(1,2));
    points_by_x.insert(Point2D(7,3));
    points_by_x.insert(Point2D(2,1));
    
    //Prints to the console: (1,2), (2,1), (7,3),
    for(auto x : points_by_x) std::cout << x << ",";
    std::cout << std::endl;
    
    
    //Prints to the console: Copy made
    auto points_x_deep_copy(points_by_x);
    
    //Prints to the console: Move performed
    auto points_x_moved_copy(std::move(points_by_x));
    
    BinarySearchTree<Point2D,PointOrderx> points_x_default_bst;
    
    // Prints to the console: Copy made
    points_x_default_bst = points_x_deep_copy ;
    
    //Prints to the console: Move performed
    points_x_default_bst = std::move ( points_x_moved_copy );
    
    
    
    
    BinarySearchTree<Point2D, PointOrdery> points_by_y;
    points_by_y.insert(Point2D(1,2));
    points_by_y.insert(Point2D(7,3));
    points_by_y.insert(Point2D(2,1));
    
    //for(auto x : points_by_y) std::cout << x << ",";
    //std::cout << std::endl;
    
    
    //Prints to the console: Copy Made
    auto points_y_deep_copy ( points_by_y ) ;
    
    //Prints to the console: Move performed
    auto points_y_moved_copy ( std::move ( points_by_y ) );
    
    BinarySearchTree< Point2D , PointOrdery> points_y_default_bst ;
    
    //Prints to the console: Copy made
    points_y_default_bst = points_y_deep_copy ;
    
    //Prints to the console: Move performed
    points_y_default_bst = std::move ( points_y_moved_copy );
    
    
    
    /*BinarySearchTree<std::string, std::greater<std::string>> names;
    names.insert("Luke");
    names.insert("Kanye");
    names.insert("Pentaatonix");
    
    //for(auto x : names) std::cout << x << ",";
    //std::cout << std::endl;
    
    
    //Prints to the console: Copy made
    auto names_deep_copy ( names ) ;
    
    //Prints to the console: Move performed
    auto names_moved_copy ( std::move ( names ) ) ;
    
    BinarySearchTree<std::string, std::greater<std::string>>names_default_bst ;
    
    //Prints to the console: Copy made
    names_default_bst = names_deep_copy ;
    
    //Prints to the console: Move performed
    names_default_bst = std::move ( names_moved_copy );*/
    
    
    /* bst.erase(6);  //{2,3,4,11,13,17}, no effect
     bst.erase(11); //{2,3,5,13,17}
     
     auto start = std::begin(bst);
     auto stop = std::end(bst);
     
     int value = 17;
     bool keep_looking = true;
     
     //std::cout << *(start++);
     
     //Find a 17 in the list
     while (start != stop && keep_looking)
     if (*start++ == value)
     std::cout<< "enter";
     keep_looking = false;
     
     --start;
     
     
     //Prints "17 is in the list."
     if (start != stop) std::cout << *start << " is in the list." << std::endl;
     
     //Construct a deep copy of bst
     BinarySearchTree deep_copy(bst);
     
     deep_copy.insert(11); deep_copy.insert(7);
     
     //Prints to the console: 2,3,5,7,11,13,17,
     for(auto x : deep_copy) std::cout << x << " ,";
     std::cout << std::endl;
     
     */
    
    system("pause");
    
    
}
