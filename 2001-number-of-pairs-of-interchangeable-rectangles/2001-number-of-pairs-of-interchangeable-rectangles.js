var interchangeableRectangles = function(rectangles) {
    const map=new Map()
    for(e of rectangles)
        map.set(e[0]/e[1],map.get(e[0]/e[1])==undefined?0:map.get(e[0]/e[1])+1)
    let res=0
    for(e of map){
        res+=(e[1]+1)*(e[1])/2
        }
    return res
};