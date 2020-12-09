# 42_cub_3d_file_parsing
file parsing for the 42 cub 3d file parsing

gcc -Wall -Werror -Wextra *.c
./a.out

treated errors:

*Resolution is limited to the default IMac screen resolution
*No double inclusion is allowed
*The initial params can be written in any order except for the map
*new lines allowed between the parameters (except for the map)
*spaces between each element and its value are allowed
*Texture files with spaces in their names are managed
*RGB for floor and ceiling is perfectly limited between [0,255]
*comas in the RGB must not be more than 2
*spaces between the rgb Colors are treated as an error
*A closed map with no new line is necessary
*Only the map caracters are allowed
*Only one player must be found inside the map

to see the results if no error is detected add the lines below in the main function inside the readfile.c
	<!-- printf("%d\n%d\n", g_width, g_height);
	printf("%s\n%s\n%s\n%s\n%s\n", g_no, g_so, g_we, g_ea, g_s);
	printf("floor rgb:%d,%d,%d\n", g_fr, g_fg, g_fb);
	printf("ceiling rgb:%d,%d,%d\n", g_cr, g_cg, g_cb);
	for(int i = 0; ugh[i]; i++)
		printf("%s\n", ugh[i]); -->

project status : ongoing
todo: changing the atoi function into my ft_atoi.
