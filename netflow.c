#include <stdio.h>
#include "graph.h"
#include <string.h>

/* new path is returned by the path parameter
*  end with a -1,
*  The function return the flow of the bottleneck edge
*  no edge exists, return 0
*/
int find_path(int *mat, int col, int row,
		int s, int d, int *path)
{
	int i, j, c_node;
	int b_neck;

	if(path == NULL || mat == NULL)
		return;


	/* the path should not be bigger than n-1 */
	for(path[0] = s, i = 0; i < row-1; i++){
		for(j = 0; j < col; j++){
			/* we can select from a set rather than check*/
			for(c_node = 0; path[c_node] >= 0; c_node++)
				if(path[c_node] == j)
					break; 
			if(path[c_node] == j)
				continue;
			if(get_mat_val(mat, path[i], j, row, col)){
				printf("%d, %d, %d\n",i+1, j, 
					get_mat_val(mat, path[i], j, 
					row,col));
				path[i+1] = j;
				break;
			}
		}
		/* no path found*/
		if(j >= col){
			if(i == 0)	return 0;
			path[i+1] = -1;
			i -= 2;
		}else if(j == d){
			path[i+2] = -1;
			break;
		}
	}

	/* find the bottle neck*/
	for(i = 2, b_neck = get_mat_val(mat, path[0], path[1], row, col); 
						path[i] >= 0; i++){
		if(get_mat_val(mat, path[i-1], path[i], row, col) < b_neck)
			b_neck = get_mat_val(mat, path[i-1], 
					path[i], row, col);
	}

	return b_neck;
}

/* record bottle neck to avoid finding path again*/
int max_netflow(int *mat, int col, int row)
{
	int *r_mat, *path;
	int i, j, p_cnt;
	int max_flow;	
	int b_neck;
	
	int t_i, t_j;

	if(mat == NULL)
		return 0;
	r_mat = (int*)malloc(sizeof(int)*col*row);	
	path = (int*)malloc(sizeof(int)*(col)+1);	

	/* initilize the residual graph*/
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++){
			set_mat_val(r_mat, i, j, 
				get_mat_val(mat, i, j, row, col), row, col);
		}

	path[0] = -1;
	path[col] = -1;	
	/*Ford_Fulkson*/
	for(max_flow = 0;
		b_neck = find_path(r_mat, col, row, 0, col-1, path);
			max_flow += b_neck){
		printf("%d---", b_neck);
		for(p_cnt = 0; path[p_cnt] >= 0; p_cnt++)
			printf("%d ", path[p_cnt]);
		printf("\n");

		for(p_cnt = 1, i = path[0], j = path[1]; 
				path[p_cnt] > 0; i = j, j = ++p_cnt){
			if(get_mat_val(mat, i, j, row, col) > 0){
				mod_mat_val(r_mat, i, j, b_neck, 
							row, col, 0);
				mod_mat_val(r_mat, j, i, b_neck, 
							row, col, 1);
			}else{
				mod_mat_val(r_mat, i, j, b_neck, 
							row, col, 1);
				mod_mat_val(r_mat, j, i, b_neck, 
							row, col, 0);
			}
		}
		for(t_i = 0; t_i < 4; t_i++){
			for(t_j = 0; t_j < 4; t_j++)
				printf("%d ", get_mat_val(r_mat, t_i, t_j,
								4 ,4));
			printf("\n");
		}
	
		for(p_cnt = 0; path[p_cnt] >= 0; p_cnt++)
			path[p_cnt] = -1;
	}
			
	free(r_mat);
	free(path);
	
	return max_flow;
}

int main()
{
	int *mat;
	int i, j;
	mat = init_graph(4, 4, 0, 100, 100, 0,
				0, 0, 1, 100,
				0, 0, 0, 100,
				0, 0, 0, 0);

	printf("%d\n", max_netflow(mat, 4, 4));
	return 0;
}
