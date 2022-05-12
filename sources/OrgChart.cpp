#include "OrgChart.hpp"

using namespace std;
namespace ariel{

OrgChart OrgChart::add_root(string name)
{
    return *this;
}

OrgChart OrgChart::add_sub(string dad,string son)
{
    return *this;
}

// OrgChart::OrgChart()
// {

// }

string* OrgChart::begin_level_order()
{
    return NULL;
}
string* OrgChart::end_level_order()
{
    return NULL;
}

string* OrgChart::begin_reverse_order()
{
    return NULL;
}
string* OrgChart::reverse_order()
{
    return NULL;
}

string* OrgChart::begin_preorder()
{
    return NULL;
}
string* OrgChart::end_preorder()
{
    return NULL;
}

ostream &operator<<(ostream &os,OrgChart &organization)
{
    return os;
}
}