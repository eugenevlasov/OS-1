#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int pid = fork ();
    char parent_filename[41] = "process_";
    char child_filename[41] = "process_";
    char buffer_parent [30];
    char buffer_child [30];
    if (pid == -1)
        printf ("Error \n");
    else if (pid != 0)
    {
        wait();
        printf("parent %d\n", getpid());
        snprintf (buffer_parent, 30, "%d", getpid());
        snprintf (buffer_child, 30, "%d", pid);
        strcat(parent_filename, buffer_parent);
        FILE * parent_file = fopen(parent_filename,"wb");
        strcat (buffer_parent, " - parent\n");
        strcat (buffer_child, " - child\n");
        fwrite(buffer_parent, strlen(buffer_parent), 1, parent_file);
        fwrite(buffer_child, strlen(buffer_child), 1, parent_file);
        fclose(parent_file);
    }
    else
    {
        printf ("child %d\n", getpid());
        snprintf (buffer_child, 30, "%d", getpid());
        strcat(child_filename, buffer_child);
        snprintf (buffer_child, 30, "%d", getppid());
        FILE * child_file = fopen(child_filename,"wb");
        fwrite(buffer_child, strlen(buffer_child), 1, child_file);
        fclose(child_file);
    }
        return 0;
}
