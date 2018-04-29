n_runs <- 1000000 #one million different games
 
got_car <- 0

for (i in 1:n_runs){
    situation <- sample(3) #number 1 is the car
    chosen <- ceil(runif(1)*3)
    if (situation[chosen] == 1){
        open <- which(situation == (ceil(runif(1)*2) + 1))
    } else{
        if (situation[chosen] == 2){
            open <- which(situation == 3)
        } else{
            open <- which(situation == 2)
        }
    }
    #change doors
    chosen <- which(!(c(1,2,3) %in% c(chosen,open)))
    if (situation[chosen] == 1){
        got_car <- got_car+1
    }
}
percentage <- got_car/n_runs * 100
cat(sprintf("Player got the car in %.2f of times\n",percentage))
