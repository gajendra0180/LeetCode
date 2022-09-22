var replaceWords = function(dictionary, sentence) {
    let arr=sentence.split(' ');
    const hash = new Map();
    for(word of dictionary){
        hash.set(word,1);        
    }
    // console.log(hash);
    let res=""
    for(word of arr){
    // [the, cattle , was ,rattled, by, the , battery] 
        let temp=""
        let doesExist=false;
        for(char of word){
            temp=temp+char;
            if(hash.get(temp)!=undefined){
                doesExist=true;
                break;
            }
        }
        if(doesExist==true){
            // console.log(temp);
            res=res+temp+" ";
        }
        else
            res=res+word+" ";
    }
    // console.log(res);
    return res.slice(0,-1);
};