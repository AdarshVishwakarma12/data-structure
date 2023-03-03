void reverse(struct node **Start){//start address have to be given to make changes!
	if(*Start == NULL){return;}
	else{
		struct node* tmp = *Start;
		struct node* tmp_1 = (*Start)->link;
		tmp->link = NULL;
		while(tmp_1!=NULL)
		{
			tmp = tmp_1;
			tmp_1 = tmp_1->link;
			tmp->link = *Start;
			*Start = tmp;
		}
	}
}