/** ls1.c
 **   purpose  list contents of directory or directories
 **   action   if no args, use .  else list files in args
 **/
#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include    <sys/stat.h>

void do_ls(char []);
void show_stat_info(char *fname, struct stat *buf);

int main(int ac, char *av[])
{
	if ( ac == 1 )
		do_ls( "." );
	else
		while ( --ac ){
			printf("%s:\n", *++av );
			do_ls( *av );
		}
}

void do_ls( char dirname[] )
/*
 *	list files in directory called dirname
 */
{
	DIR		        *dir_ptr;		/* the directory */
	struct dirent	*direntp;		/* each entry	 */
	struct stat     dirent;          

	if ( ( dir_ptr = opendir( dirname ) ) == NULL )
		fprintf(stderr,"ls1: cannot open %s\n", dirname);
	else
	{
		while ( ( direntp = readdir( dir_ptr ) ) != NULL ){

			 if( stat(direntp->d_name, &dirent) != -1 ){
			 	show_stat_info(direntp->d_name, &dirent);
			 }
			 else {
			 	perror(direntp->d_name);
			 }
		}
		
		closedir(dir_ptr);
	} 
}

void show_stat_info(char *fname, struct stat *buf)
/*
 * displays some info from stat in a name=value format
 */
{
    printf("   mode: %o\n", buf->st_mode);         /* type + mode */
    printf("  links: %d\n", buf->st_nlink);        /* # links     */
    printf("   user: %d\n", buf->st_uid);          /* user id     */
    printf("  group: %d\n", buf->st_gid);          /* group id    */
    printf("   size: %lld\n", buf->st_size);         /* file size   */
    printf("modtime: %ld\n", buf->st_mtime);        /* modified    */
    printf("   name: %s\n", fname );               /* filename    */
    printf("\n");
}

/*

answers to the tutorial question 

Question 1)

  111 101 101
  111 100 000
  111 110 100
  110 100 100
  110 110 100

 Question 2)

   mkdir -p a/b/{d,e} && a/c/{f,g,h} ;

*/