#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    // template<class T>
    class OrgChart
    {
        public:

        OrgChart add_root(string name);   
        OrgChart add_sub(string dad,string son);

        // OrgChart();

        string *begin_level_order();
        string *end_level_order();
      
        string *begin_reverse_order();
        string *reverse_order();

        string *begin_preorder();
        string *end_preorder();

        string *begin(){ return begin_level_order();}
        string *end(){return end_level_order();}

        friend ostream &operator<<(ostream &os,OrgChart &organization);

    };
}