function fetchData(callback){
    //console.log("Accept Arguments: \n" + ` ${process.argv}` );
}

let a = process.argv;
for(i=2; i<a.length; i++){
    console.log(a[i] + ",")
}

fetchData();
// for(i=0; i<a.length; i++){
//     console.log(a[i]);
// }