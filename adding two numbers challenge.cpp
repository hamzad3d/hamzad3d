#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * 
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int listNodeLength(ListNode* list_node)
{
    int len = 0;
    while(list_node)
    {             
        ++len;
        list_node = list_node->next;
    }
    return len;
}

  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // determine which is greater than the other 
        int l1_len = listLength(l1) ;
        int l2_len = listLength(l2) ;

        // create dummies to handle 
        // the compared ones. 
        ListNode* greater = nullptr;
        ListNode* least   = nullptr;
        
        // start assigning in reverse
        // order as default case
        greater = l2 ;
        least   = l1 ;
        
        // test lengths and re-assign the case
        // if needed
        if(l1_len > l2_len || l1_len == l2_len)
        {
            // in this case weather
            // l1 is gearter or equal 
            // they are the same. 
            greater = l1 ;
            least   = l2 ;
        } 

        // prepare main output list handler 
        ListNode* output = nullptr;

        // lets start through 
        // the greater one 
        int carrier = 0 ; // to handle tens 
        while(greater)
        {
            int output_val = 0; // is the value of current order
            
            int least_val  = 0;   
            
            // while least exists
            // set least_val and 
            // pass the next node
            // to the next iteration
            if(least)
            {
                least_val = least->val;
                least     = least->next;
            }

            // carrier     : 0 | 0 | 1 | 1 | 1
            //---------------- |---| - |---| ----
            // l1          : 2 | 9 | 4 | 9 |  
            // l2          : 4 | 3 | 8 |   |  
            //---------------- |---| - |---| ----
            // output_val  : 6 | 2 | 2 | 0 | 1

            int result = carrier + greater->val + least_val ;
            output_val = result % 10;
            carrier    = result >= 10;    

            // go througth the nodes and find 
            // null one to assign a new node 
            nextNode(&output,output_val);

            // pass next node to the next iteration            
            greater    = greater->next;
        }

        // if the carrier is got out the while 
        // loop with '1' , then put it into the
        // tail of the node list  
        if (carrier > 0)
        {
            nextNode(&output,carrier);
        }
        
        // set output
        return output;
    }
 
    int listLength(ListNode* list_node)
    {
        int len = 0;
        while(list_node)
        {             
            ++len;
            list_node = list_node->next;
        }
        return len;
    }

    void nextNode(ListNode** node,int val)
    {   
        //if node is null create one 
        // and exit the function else 
        // go through the nodes to get null one 
        if(*node == nullptr)
        {
            *node = new ListNode(val);
        }
        else
        {
            nextNode(&( (*node)->next ), val);
        }  
    }

};



int main()
{
    ListNode l1 ,l2 ;
    l1.val = 5;
    l1.next = new ListNode(6);
    l2.val = 3;
    l2.next = new ListNode(3);

    Solution s;
    ListNode * result = s.addTwoNumbers(&l1,&l2);

    int len = listNodeLength(result);

    int* output = new int[len];
    int *pStart = output;
    int *pEnd = output+len;

    while(result)
    {
        *output = result->val; 
        ++output;               
        result = result->next;
    }
     
    system("cls");
    cout<< "================"<<endl;
    cout<< "program begins"<<endl;
    cout<< "================"<<endl;
    cout<< "len:"<<len<<endl;
    cout<< "result:";
    output = pStart;
    for (int i=0; i < len ; i++)
    {
        cout<< output[i];
    }    
    cout<<endl;    
    cout<< "================"<<endl;
    cout<< "program ends"<<endl;
    cout<< "================"<<endl;

    return 0;
}