function call(callback){
    let promise = new Promise(
        (req,res) => {
            res();
        },
        promise.then(
            () => {
                setInterval(callback,2000);
                call(
                    () => {console.log("Hello World")}
                 );
            }
        )
    );
}