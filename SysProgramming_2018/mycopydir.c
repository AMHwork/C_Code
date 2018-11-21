/** mycopydir.c - copies everything (files and sub-directories) from dir1 to dir2
 ** dir1 and dir2 are from the command line arguments
 ** ------------------------------------------------------------
 *
 *
 */
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include    <unistd.h>
#include	<string.h>
#include	<errno.h>
#include	<fcntl.h>

#define BUFFERSIZE      4096
#define COPYMODE        0644
#define	FILE_MODE	S_IRWXU

void oops(char *, char * );
int content(char * );
void copy_file( char *, char * );
void copy_dir(char *, char * );
ino_t get_inode( char * );
void printpathto( ino_t );
void inum_to_name(ino_t , char *, int );

char inode_name[BUFFERSIZE];

int main(int ac, char *av[])
{

    /*insert you code here*/
    // if destination folder does not exist then make the new directory
	// if destination does exit assume it has no subdirectories or files 
	// if the source directory name is the same as the destionation, abort program

	printpathto(get_inode("."));
	copy_dir( av[1], av[2] );
	return 0;
}

void copy_dir( char dir_src[] , char dir_dst[] )
/*
 *  copy files and sub_directories from dir_src to dis_dst
 */
{
    DIR   *dir_ptr;   /* the directory */
    struct dirent *direntp;   /* each entry  */

    char    srcString[BUFFERSIZE];
    char    dstString[BUFFERSIZE];
    char    inital[BUFFERSIZE];
    struct  stat  info;

    strcpy(inital,inode_name);
    printf("%s\n", inital);
    printf("%s\n", dir_src);

    if (strlen(dir_src) < strlen(inital)){
        strcpy(srcString,inode_name);
        strcat(srcString,"/");
        strcat(srcString,dir_src);
        printf("%s\n", srcString);
    }
    else {
        chdir(dir_src);
        strcat(srcString,"/");
        strcpy(srcString,dir_src);
        printf("%s\n", srcString);
    }

     if (strlen(dir_dst) < strlen(inital)){
        strcpy(dstString,inode_name);
        strcat(dstString,"/");
        strcat(dstString,dir_dst);
        printf("%s\n", dstString);
    }
    else {
        chdir(dir_dst);
        strcat(dstString,"/");
        strcpy(dstString,dir_dst);
        printf("%s\n", dstString);
    }

    if ( ( dir_ptr = opendir( srcString ) ) == NULL )
        fprintf(stderr,"cannot open source directory %s\n", srcString);
    else
    {
        printf("making dir: %s\n", dir_dst);
        mkdir(dstString, 0755);

        while ( ( direntp = readdir( dir_ptr ) ) != NULL ){

            char file[BUFFERSIZE];
            strcpy(file, srcString);
            strcat(file, "/");
            strcat(file, direntp->d_name);
            printf("%s\n", file);

            if( stat(file, &info) == -1 ){
                fprintf(stderr, "cannot stat %s.\n",  file );
            }

            if (!strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..")
                || !strcmp(direntp->d_name, ".DS_Store")) {
                // ingnore these files in the directory
            } 
            else {
              
                if (content(file) == 1) {

                    char copyString[BUFFERSIZE];
                    strcpy(copyString, srcString);
                    strcat(copyString, "/");
                    strcat(copyString, direntp->d_name);
                    printf("%s\n", copyString);

                    chmod(copyString, 0755);

                    // copy to destination
                    char copyDst[BUFFERSIZE];
                    strcpy(copyDst, dstString);
                    strcat(copyDst, "/");
                    strcat(copyDst, direntp->d_name);
                    printf("%s\n", copyDst);

                    printf("finishing copying the file!\n");
                    copy_file(copyString, copyDst);

                } 
                else if (content(file) == 2) {
                    
                    printf("Found a Directory!\n");
                    char copySrcfolder[BUFFERSIZE];
                    strcpy(copySrcfolder, srcString);
                    strcat(copySrcfolder, "/");
                    strcat(copySrcfolder, direntp->d_name);
                    printf("%s\n", copySrcfolder);

                    // copy to destination
                    char copyDstfolder[BUFFERSIZE];
                    strcpy(copyDstfolder, dstString);
                    strcat(copyDstfolder, "/");
                    strcat(copyDstfolder, direntp->d_name);
                    printf("%s\n", copyDstfolder);

                    printf("Reading the content of the Directory!\n");
                    copy_dir(copySrcfolder, copyDstfolder);

                } 
                else {
                    perror(direntp->d_name);
                }
            }

            // if it is a file or directory
        }

        closedir(dir_ptr);

    }

 }



void printpathto( ino_t this_inode )
/*
 *	prints path leading down to an object with this inode
 *	Obtain from the lecture slides
 */
{
	ino_t	my_inode ;
	char	its_name[BUFFERSIZE];

	if ( get_inode("..") != this_inode )
	{
		chdir( ".." );				/* up one dir	*/

		inum_to_name(this_inode,its_name,BUFFERSIZE);/* get its name*/
		my_inode = get_inode( "." );		/* print head	*/
		printpathto( my_inode );		/* recursively	*/
		strcat(inode_name, "/");
		strcat(inode_name, its_name);
	}
}

void inum_to_name(ino_t inode_to_find , char *namebuf, int buflen)
/*
 *	looks through current directory for a file with this inode
 *	number and copies its name into namebuf
 *  Obtain from the lecture slides
 */
{
	DIR		*dir_ptr;		/* the directory */
	struct dirent	*direntp;		/* each entry	 */

	dir_ptr = opendir( "." );
	if ( dir_ptr == NULL ){
		perror( "." );
		exit(1);
	}

	/*
	 * search directory for a file with specified inum
	 */

	while ( ( direntp = readdir( dir_ptr ) ) != NULL )
		if ( direntp->d_ino == inode_to_find )
		{
			strncpy( namebuf, direntp->d_name, buflen);
			namebuf[buflen-1] = '\0';   /* just in case */
			closedir( dir_ptr );
			return;
		}
	fprintf(stderr, "error looking for inum %llu\n", inode_to_find);
	exit(1);
}


void copy_file( char *file_src, char *file_dst )
/*
 * copy file from file_src to file_dst
 * Obtain most from the lecture slides/practical examples
 */

{
	int     in_fd, out_fd;
	ssize_t n_chars;
    char    buf[BUFFERSIZE];

	/* insert your code here */
	// first obtain the information about the file
	// scan all the information
	// if there is a file already made then don't make else make

	if ((in_fd = open(file_src, O_RDONLY)) == -1){
		oops("cannot open ", file_src);
	}
	if ((out_fd = creat(file_dst, COPYMODE)) == -1){
		oops("cannot open ", file_dst);
	}

	while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0){
		if (write(out_fd, buf, (size_t)n_chars) != n_chars){
			oops("write error to", file_src);
		}
	}
	if (n_chars == -1){
		oops("Read errpr from ", file_src);
	}

	if (close(in_fd) == -1 || close(out_fd) == -1){
		oops("Error closing files", "");
	}

}

void oops(char *s1, char *s2)
/*
 *  Output the error message and exit
 *  Obtain from the lecture slides
 */

{
      fprintf(stderr,"Error: %s ", s1);
      perror(s2);
      exit(1);
}

ino_t get_inode( char *fname )
/*
 *	returns inode number of the file
 *  Obtain from the lecture slides
 */
{
	struct stat info;

	if ( stat( fname , &info ) == -1 ){
		fprintf(stderr, "Cannot stat ");
		perror(fname);
		exit(1);
	}

	return info.st_ino;
}


int content(char *str)
/*
 * boolean: tells if arg name is a directory, file or empty
 */
{
	struct stat info;
	int check = 0; // marker for the content

	if ( stat( str , &info ) == -1 ){
		fprintf(stderr, "its is empty\n");
		check = -1;
	} 
	else if ((info.st_mode & 0170000)==0040000){
		check = 2;
	}
	else if ((info.st_mode & 0170000)==0100000){
		fprintf(stderr, "Found a file!\n");
		check = 1;
	}
 
	return check;

}


