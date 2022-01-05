#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
  
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 
  
// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// trie node 
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 

struct TrieNode *getNode(void);
void insert(struct TrieNode *root, const char *key);
bool search(struct TrieNode *root, const char *key);



/*Example:

	// Input keys (use only 'a' through 'z' and lower case) 
    char keys[][8] = {"the", "a", "there", "answer", "any", 
                     "by", "bye", "their"}; 
  
    char output[][32] = {"Not present in trie", "Present in trie"}; 
  
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    int i; 
    for (i = 0; i < ARRAY_SIZE(keys); i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    printf("%s --- %s\n", "the", output[search(root, "the")] ); 
    printf("%s --- %s\n", "these", output[search(root, "these")] ); 
    printf("%s --- %s\n", "their", output[search(root, "their")] ); 
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] ); 
  
    return 0;

*/