class Solution
{
    public:
    // your task is to complete this function
    void reverse(Node **head){
        Node *pre = NULL,*cur = *head;
        while(cur){
            Node *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        *head = pre;
    }
    
    Node* merge(Node **r1, Node **r2){
        if(*r1==NULL){
            return *r2;
        }
        if(*r2 == NULL){
            return *r1;
        }
        Node *r = new Node(0);
        Node *ptr = r;
        while(*r1 and *r2){
            if((*r1)->data<(*r2)->data){
                ptr->next = *r1;
                *r1 = (*r1)->next;
            }
            else{
                ptr->next = *r2;
                *r2 = (*r2)->next;
            }
            ptr = ptr->next;
        }
        
        while(*r2){
            ptr->next = (*r2);
            ptr = ptr->next;
            *r2 = (*r2)->next;
        }
        while(*r1){
            ptr->next = (*r1);
            ptr = ptr->next;
            *r1 = (*r1)->next;
        }
        
        if(ptr){
            ptr->next = NULL;
        }
        return r->next;
    }
    
    void sort(Node **head)
    {
        Node *r1 = new Node(0);
        Node *r2 = new Node(0);
        Node * ptr = *head;
        Node *f = r1,*s = r2;
        while(ptr){
            f->next = ptr;
            ptr = ptr->next;
            f = f->next;
            
            if(ptr){
                s->next = ptr;
                s = s->next;
                ptr = ptr->next;
            }
        }
        if(f){
            f->next = NULL;
        }
        if(s){
            s->next = NULL;
        }
        
        reverse(&(r2->next));
        
        *head = merge(&(r1->next),&(r2->next));
        
    }
};
