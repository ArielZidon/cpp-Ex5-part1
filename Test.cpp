#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("get no father")
{
    OrgChart organization;
    organization.add_root("CEO")
        .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO

    //   cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
    //        CEO
    //        |--------|--------|
    //        CTO      CFO      COO
    //        |                 |
    //        VP_SW             VP_BI
    //  */

    CHECK_NOTHROW(organization.add_sub("VP_BI", "New Employee"));
    CHECK_THROWS(organization.add_sub("vice presedent", "New"));
    CHECK_NOTHROW(organization.add_root("vice presedent"));
    CHECK_NOTHROW(organization.add_sub("vice presedent", "New"));

    for(int i = 0;i<100;i++)
        CHECK_THROWS(organization.add_sub("no body", "someone"));
}

TEST_CASE("organization 1")
{
    vector<string> roles = {"SHAIN", "ESTER", "TAIR", "DANIEL", "DVIR", "ARIEL"};
    vector<string> level_order = {roles[0], roles[1], roles[2], roles[3], roles[4], roles[5]};
    vector<string> reverse_order = {roles[4], roles[5], roles[1], roles[2], roles[3], roles[0]};
    vector<string> preorder = {roles[0], roles[1], roles[4], roles[2], roles[3], roles[5]};
    OrgChart organization;
    organization.add_root(roles[0])
        .add_sub(roles[0], roles[1])  
        .add_sub(roles[0], roles[2])  
        .add_sub(roles[0], roles[3])  
        .add_sub(roles[1], roles[4]) 
        .add_sub(roles[3], roles[5]); 
    //        SHEIN
    //        |--------|--------|
    //        ESTER   DANIEL     TAIR
    //        |                 |
    //        DVIR             ARIEL
    //  */
    size_t i = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(level_order[i++], (*it));
    } 
    i = 0;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        CHECK_EQ(reverse_order[i++], (*it));
    } 
    i = 0;
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
        CHECK_EQ(preorder[i++], (*it));
    } 
    i = 0;
    for (auto element : organization)
    { 
        CHECK_EQ(level_order[i++], element);
    } 
    i = 0;
    // demonstrate the arrow operator:
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(level_order[i++].size(), it->size());
    } 
}
