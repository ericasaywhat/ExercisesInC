/*
   C Program that reads a text file, splits lines into words,
   and counts the frequency of each word, all using GLib.The
   text file is of Shakespeare's sonnets from Project
   Gutenberg exists in the same directory as this file.

   author: Erica Lee
   last modified: 2 April 2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

GHashTable *makeHashtable(){
	return g_hash_table_new(g_str_hash, g_str_equal);
}

void getTextString(gchar *filename, gchar** contents){
	GError *err = NULL;
	g_file_get_contents(filename, contents, NULL, &err);
	if (err != NULL) {
    	g_assert (contents == NULL);
    	fprintf (stderr, "Unable to read file: %s\n", err->message);
    	g_error_free (err);
  	} else{
    	g_assert (contents != NULL);

  }
}


void updateHash(GHashTable *hashtable, gpointer key){
	gpointer val = g_hash_table_lookup(hashtable, key);
	val = val ? val+1 : (gpointer) 1;
	g_hash_table_replace(hashtable, key, val);
}

void getWordTable(GHashTable *hashtable, gchar *string, gchar **wordlist){
	wordlist = g_strsplit(string, " ", -1);
    int i = 0;
    while(wordlist[i] != NULL){
    	updateHash(hashtable, wordlist[i]);
    	i++;
    }
}


void printHashTable(GHashTable *hashtable){
	void printKeyVal(gpointer key, gpointer value, gpointer userdata){
		printf("key: %s,freq: %i \n", key, value);
	}

	g_hash_table_foreach(hashtable, printKeyVal, NULL);

}

int main(int argc, char** argv) {
	GHashTable *hashtable = makeHashtable();
    gchar *sonnets_as_string;
    gchar *wordlist;
    gchar *filename = "sonnets.txt";

    getTextString(filename, &sonnets_as_string);
    getWordTable(hashtable, sonnets_as_string, &wordlist);
    printHashTable(hashtable);

    return 0;
}