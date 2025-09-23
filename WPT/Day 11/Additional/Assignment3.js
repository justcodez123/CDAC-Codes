function pattern()
{
    let num=process.argv[2];
    if(num>0 && num<6)
    {

        for(let i=0;i<num;i++)
        {
            for(let j=0;j<num-i;j++)
            {
                process.stdout.write("*");
            }
            console.log()
        }

    }else{
        console.log("Error number should be less than 6 and greater than 0");
    }
}

pattern();