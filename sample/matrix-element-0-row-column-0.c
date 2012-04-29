// Store the row and column index with //value 0. Let the dimension be mxn
 for (int i = 0; i < m; i++){
 for (int j = 0; j < n;j++){
 if (matrix[i][j] == 0){
 row[i] = 1;
 column[j] = 1;
}
}
}

// Set arr[i][j] to 0 if either row i or column j //has a 0
 for (int i = 0; i < m; i++){
 for (int j = 0; j < n; j++){
 if ((row[i] == 1 || column[j] == 1)){
 matrix[i][j] = 0;
}
}
