#include "substring.h"

#define INDEX(x) ((x) - 'a')

/**
 * free_trie - frees all nodes of trie
 * @root: pointer to root
 */
void free_trie(Tree *root)
{
	int i = 0;

	for (i = 0; i < 26; i++)
		if (root->children[i])
			free_trie(root->children[i]);
	free(root);
}

/**
 * search_trie - searches trie for word
 * @node: root of tree
 * @str: string to find
 * @k: characters of str to find
 * @memmory: the memoization array
 * @j: index in memmory
 * Return: 1 if found else 0
 */
int search_trie(Tree *node, char *str, int k, Tree **memmory, int j)
{
	for (; k; str++, k--)
	{
		if (!node->children[INDEX(*str)])
			return (0);
		node = node->children[INDEX(*str)];
	}

	memmory[j] = node;
	if (node->left-- > 0)
	{
		return (1);
	}
	return (0);
}

/**
 * make_trie - fills trie with words
 * @root: pointer to root of trie
 * @words: pointer to array of words
 * @nb_words: number of words
 * @nodes: array of trie nodes to populate
 */
void make_trie(Tree *root, char const **words, int nb_words, Tree **nodes)
{
	int i = 0;
	char const *str;
	Tree *node;

	for (i = 0; i < nb_words; i++)
	{
		node = root;
		for (str = words[i]; *str; str++)
		{
			if (!node->children[INDEX(*str)])
			{
				node->children[INDEX(*str)] = calloc(1, sizeof(Tree));
				if (!node->children[INDEX(*str)])
					exit(1);
			}
			node = node->children[INDEX(*str)];
		}
		node->word = 1;
		node->count++;
		node->left++;
		node->val = (char *)words[i];
		nodes[i] = node;
	}
}
/**
 * find_substring - finds substring composed of all concatenated words
 * @s: the string to search
 * @words: array of contentated words to find
 * @nb_words: the size of passed array
 * @n: size of return array, to set
 * Return: array of indexes where all words found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, j, k, lenstr, matches;
	Tree *root, **nodes, **memmory;
	int *indexes;

	*n = 0;
	lenstr = strlen(s);
	k = strlen(words[0]);
	indexes = calloc(lenstr, sizeof(int));
	root = calloc(1, sizeof(Tree));
	nodes = calloc(nb_words, sizeof(*nodes));
	memmory = calloc(lenstr, sizeof(*memmory));
	if (!indexes || !root || !nodes || !memmory)
		exit(1);
	make_trie(root, words, nb_words, nodes);

	for (i = 0; i < lenstr; i++)
	{
		matches = 0;
		for (j = i; j <= lenstr - k; j += k)
		{
			if ((memmory[j] && memmory[j]->left-- > 0) ||
				search_trie(root, (char *)s + j, k, memmory, j))
			{
				if (++matches == nb_words)
				{
					indexes[*n] = i;
					*n += 1;
					break;
				}
			}
			else
				break;
		}
		for (j = 0; j < nb_words; j++)
			nodes[j]->left = nodes[j]->count;
	}
	free_trie(root), free(nodes), free(memmory);
	if (*n == 0)
		indexes = (free(indexes), NULL);
	return (indexes);
}
