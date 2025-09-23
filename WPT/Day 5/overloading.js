function call(...a){
    sum = 0;
    a.forEach((k)=>console.log(k))
    a.forEach((e) => sum += e)
    console.log(`addiion is ${sum}`);

    console.log(`and Maximum No. in array: ${Math.max(...a)} `)
}

call(12, 23, 56);

call(12, 23);

call(12, 23, 56, 89);