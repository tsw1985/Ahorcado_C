struct int_array{
    int size;
    int *array_pointer;

};
int_array *index_of(char *wordToSearch , char *letter);
int exists_char_on_string(char *string_to_search, char *letter);
void clean_world_end_rare_symbol(char *_word);