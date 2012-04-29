Node * reverse( Node * ptr )
{
    Node * temp;
    Node * previous = NULL;
    while(ptr != NULL) {
        temp = ptr->next;
        ptr->next = previous;
        previous = ptr;
        ptr = temp;
    }
    return previous;
}
