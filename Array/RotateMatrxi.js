const rotate = (matrix) => {

    //transposing the matrix
    for(let i=0; i<matrix.length; i++){
        for(let j=i+1; j<matrix.length;j++){
            let temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(let i=0; i<matrix.length; i++){
        matrix[i].reverse();
    }

    return matrix;
}

let matrix = [[1,2,3],[4,5,6],[7,8,9]];

const reversed = rotate(matrix);

console.log(reversed);
