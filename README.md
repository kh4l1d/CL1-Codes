# CL1-Codes
Instructions and solutions to common issues (please read) ->
--------------------------------------------------------------------------------------------------------------------------------

### Downloading :wink:

1. Say you want to download the binarySearch.py file through the terminal, just enter in the following command: 

       `wget https://raw.githubusercontent.com/kh4l1d/CL3-Codes/master/binarySearch.py`
       

2. It's of the form: 

       `wget URL/file.txt`

3. Although it is worth mentioning that repos should ideally be "git clone"-d like this: https://www.youtube.com/watch?v=oDUOWC4yib0

### Other similar works (neatly organzied and loaded with cringy (or is it cringey ?) jokes) ->

1. BE Sem2 CL3-Codes -> https://github.com/kh4l1d/CL3-Codes

2. TE Sem1 & Sem2 (Download link) -> https://www.dropbox.com/s/jlsz28bgrpkx7us/Khalid%27s%20Third%20Year.zip?dl=0

3. SE Sem1 & Sem2 (Download link) -> https://www.dropbox.com/s/158agkqibt2cgoh/Khalid%27s%20Second%20Year.zip?dl=0

--------------------------------------------------------------------------------------------------------------------------------
### travellingSalesman.cpp

1. Please see the link mentioned in the code to understand what's going on.

2. To get the sequence in which cities were travelled, print out the contents of a when i==n

3. While constructing the graph, make sure that in the matrix you plot - if a path doesn't exist from say A to B,then assign a value like 999 to that place (a large value indicates that a path does not exist between those vertices).

4. Make sure that the initial value assigned to cost is huge compared to the costs you assign when there is no existing path between cities. For example, in the above point, we assigned 999 - so make sure your initial cost is something like 9999.

--------------------------------------------------------------------------------------------------------------------------------
### kMeans.cpp

1. Make sure the centroid you choose,belongs to one of the points.

2. The end result of the centroids will always be same (provided the points are same of course) as the code runs till hasAchievedPerfectCentroids = true.

--------------------------------------------------------------------------------------------------------------------------------
### knapsack.cpp

1. Keep in mind, the 0/1 knapsack problem is solved using the branch and bound approach.

2. Watch [this video](https://www.youtube.com/watch?v=R6BQ3gBrfjQ) for a proper explanation.

--------------------------------------------------------------------------------------------------------------------------------
### LEX and YACC programs

1. If you installed bison:
       
        bison -d <yacc_file>.y
        flex <lex_file>.l
        gcc lex.yy.c <yacc_file>.tab.c -lm
        ./a.out
       
        
2. If not:

        yacc -d <yacc_file>.y
        flex <lex_file>.l
        gcc lex.yy.c <yacc_file>.tab.c -lm
        ./a.out  
   
        
