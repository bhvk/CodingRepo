/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    //this recursive func returns tail
    Node* flatten_rec(Node* head)
    {
        Node* curr = head;
        Node* tale = head;
        while(curr)
        {
            Node* next = curr->next; //crucial

            if(curr->child)
            {
                curr->next = curr->child;
                curr->child = nullptr;
                curr->next->prev = curr;

                tale = flatten_rec(curr->next);
                tale->next = next;
                if(next)
                {
                    // tale->next = next; //not here because we want last element pointing to null
                    next->prev = tale;
                }
                //jumping all the flattened nodes
                curr = tale;
            }
            else
                curr = next;

            //keep incrementing tail along with curr till last available current
            if(curr) tale = curr;
        }
        return tale;
    }
    Node* flatten(Node* head)
    {
        if(head)
            flatten_rec(head);
        return head;
    }

};

/*
Node* flatten(Node* head)
{
    if(head)
        flatten_rec(head);
    return head;

    Node* A = head;
    Node* B = A->next;
    // B->prev = A;
    // A->prev = head; //questionable

    while(A->next || A->child)
    {
        if(A->child)
        {
            A->child->prev = A;
            // Node* C = B;
            A->next = A->child;
            B->prev = flatten(A->child);
            (flatten(A->child))->next = B;
            // B->next = C;
            // C->prev = B;
        }
        else
        {
            B->prev = A;
            A = B;
            B = A->next;
        }
    }
    return head;
}
*/
