

<h4>1. PROBLEM STATEMENT</h4>

Given a 2D digital image in PGM (binary/ascii), the problem is to find the outer isothetic cover, inner isothetic cover and the convex hull. The image is registered on a gird of horizontal and vertical lines whose size (grid size) is determined by user input. 

<h4>2. INTRODUCTION</h4>

Determination of the (minimum) maximum-area (outer) inner isothetic cover corresponding to a 2D digital object is a problem of practical relevance to various fields. Given a set of isothetic grid lines under the object plane, an isothetic cover corresponds to a collection of isothetic polygons, which bears a structural and geometric relation with the concerned object, and hence can be useful to many interesting applications, such as VLSI layout design, computation of a minimum-area safety region, referred as the classical safety zone problem, may be necessary to ensure the correctness of design rules before fabricating an integrated circuit.


<h5>2.1 IMPORTANT TERMS AND DEFINITIONS</h5>

Isothetic polygon-An isothetic polygon is a polygon whose alternate sides belong to two parametric families of straight lines. The most well-known example of isothetic polygons are rectilinear polygons, and the former term is commonly used as a synonym for the latter one. For this problem, rectilinear polygons are considered, with the 2 families being parallel to the x-axis and the y-axis.

Unit Grid Block(UGB)/Cell: The grid divides the image into blocks of digital points(pixels) each having their side length g.

Outer isothetic cover: A a rectilinear polygon inside which the image is contained wholly. 


Inner Isothetic Cover : A rectilinear polygon of maximum area which is wholly contained inside the image.

Grid size(g): It is the number of pixels which will be considered as the smallest unit,while constructing the covers. 

Convex hull : A convex hull is a convex(without any concavity) polygon inside which the image is contained wholly.If we join any two points in the hull by a line segment, all the points on the line segment are contained inside the hull.


Vertex : The point of intersection of a vertical and a horizontal line of the cover is called the vertex of that cover. 

Vertex types (t): 4 main types of vertices are defined, in the basis of object occupancy of UGBs/cells.

Occupied Cell: a cell is occupied if a)for outer cover-it has even a single pixel whose grayscale value is less than the scale of the image b)for inner cover-all the pixels of the cell have grayscale values less the scale of the image

Unoccupied Cell: a cell is unoccupied if a)for outer cover-all the pixels of the cell have grayscale values equal to the scale of the image a)for inner cover-it has even a single pixel whose grayscale value is equal to the scale of the image

Point: Point is the intersection of grid lines in the image.while considering a point,the four cells containing the point are considered.The cells are named as C1, C2,C3 and C4 respectively starting from top right and moving clockwise.(elaborated later).

Image noise: (henceforth referred to simply as noise) -any unwanted pixels which distort the image and affect the cover creation process.


<h4>3. Proposed Solution</h4>
If the entry point of such a region can be recognized during the traversal of a polygon belonging to an isothetic cover, then instead of following the path entering the complex region, the alternative path along the grid lines can be chosen. Such a strategy would be entirely free of the backtracking process, and
hence can construct the isothetic cover in a simpler and faster way.
The proposed algorithm does not require any backtracking of the already traversed path. Also, the concept of background grid has been introduced whose resolution can be varied to enable fine or coarse analysis of the underlying shape he strength of the proposed algorithm lies in the fact that it takes into account the combinatorial arrangement of the grid lines with respect to the object while simultaneously traversing and determining the boundary of the polygon defining an isothetic cover.

<h5>3.1 Outline of the Algorithm:</h5>
1. Input a PGM image from a file and the grid size from the user input. Rmove noise.
2. Construction of the outer cover.
3. Construction of the inner cover.
4. Construction of the convex hull.


<h4>4. PGM Specification</h4>

There are two types of PGM images:
1. Plain PGM: P2
2. Raw PGM : P5
A PGM P5 file consists of a sequence of one or more PGM images. There are no data, delimiters, or padding before, after, or between images. 
Each PGM image consists of the following: 
1. A "magic number" for identifying the file type. A pgm image's magic number is the two characters "P5". 
2. Whitespace (blanks, TABs, CRs, LFs). 
3. A width, formatted as ASCII characters in decimal. 
4. Whitespace. 
5. A height, again in ASCII decimal. 
6. Whitespace. 
7. The maximum gray value (Maxval), again in ASCII decimal. Must be less than 65536, and more than zero. 
8. A single whitespace character (usually a newline). 
9. A raster of Height rows, in order from top to bottom. Each row consists of Width gray values, in order from left to right. Each gray value is a number from 0 through Maxval, with 0 being black and Maxval being white. Each gray value is represented in pure binary by either 1 or 2 bytes. If the Maxval is less than 256, it is 1 byte. Otherwise, it is 2 bytes. The most significant byte is first. 
10. A row of an image is horizontal. A column is vertical. The pixels in the image are square and contiguous. 

In case of a P2 we see the following difference:
      There is exactly one image in a file. 
The magic number is P2 instead of P5. 
Each pixel in the raster is represented as an ASCII decimal number (of arbitrary size). 
Each pixel in the raster has white space before and after it. There must be at least one character of white space between any two pixels, but there is no maximum. 
No line should be longer than 70 characters. 

<h4>5. Noise Removal</h4>

Algorithm:

Step 1: Add the values at each pixel where the gray scale value is less than the scale of the image  

Step 2: Find the average value by dividing the total value by the total number of pixels that have gray scale value less than the scale.

Step 3: Add an adjustment factor(say 50) to the average value. This is the new average.

Step 4: If the value of a pixel is less than the average value,make the value of the pixel=image scale,otherwise make it equal to the image scale.

Step 5: If pixel value is less than average, make it equal to average, otherwise make it equal to the image scale


<h4>6. Construction of the outer cover</h4>

The algorithm for constructing the Outer isothetic cover (OIC), of a digital object S that consists of only one connected component is presented here. Here we assume that the top left point pₒ(iₒ,jₒ) is given. The start point of traversal, qs, is first determined from pₒ. Then the construction starts from qs and ends when the traversal reaches qs. The traversal is guided by the type of each grid point q, which is obtained from the corresponding class of q. The type t of q corresponding to its internal angle 90o, 180 o, and 270 o, w.r.t. an isothetic polygon is considered to be 1, 0 and -1, respectively.
The algorithm outputs P(S) as an ordered set of vertices. The information stored corresponding to each vertex are its coordinates and type.

 <h5>6.1. Classification of grid points:</h5>
An isothetic polygon has two types of vertices with internal angles 90 o and 270 o (i.e. -90 o). The procedure for finding the OIC is based on classifying the grid points while constructing the OIC. The type of any grid point, q (i ,j), is determined using the object occupancies of its neighbouring UGBs and their combinatorial arrangements.
      Unit Grid Block, UGB(i,j) is described by two horizontal and two vertical segments. Since S is 8-connected and a grid segment is 4-connected, the  intersection between them is well defined. Hence, UGB(i,j) is said to have an object occupancy if and only if there exists a point p such that it belongs to intersection of the UGB(i,j) and S.
In this case the UGB(i.j)I is said to object occupancy. 
Hence, for each UGB, Ua (a =1, 2, 3, 4 ), incident at q(i,j), there
are two possibilities: either Ua S ≠   or Ua  S = , thus giving rise
to, 24 = 16 possible arrangements of the four UGBs. These 16 possible arrangements are further grouped into five combinatorial
classes in our algorithm, where class Cm includes all arrangements for which exactly m out of four neighbouring UGBs of q have object occupancy and the remaining 4-q ones do not have any object occupancy.


<h5>6.2. Arrangement of UGBs:</h5>

Grid points will belong to one the following five categories depending upon object occupancy:

1. C0: None of the four UGBs have object occupancy.
2. C1: Exactly one out of the four UGBs have object occupancy. Four such possible arrangements based on the UGB having occupancy.
3. C2: Two out of the four have object occupancy. Here again there are two arrangements possible.
i. UGBs having a grid segment in common i.e. adjacent.
ii. Do not have a grid segment in common .i.e diagonally opposite.
4. C3 : Three UGBs have object occupancy. Four arrangements are possible depending on the UGB that has no occupancy.
5. C4 :  All the four UGBs have object occupancy.
6. The interior of a UGB lies outside the outer isothetic cover if and only if UGB has no object occupancy.
7. A grid segment s belongs to the boundary of the cover if and only if, out of the two UGBs having s in common, the interior of one lies outside and that of the other lies inside the cover.

<h5>6.3. Classification of Vertices:</h5>

1. A vertex is a 90 vertex if it belongs to class C1.
2. A grid point is a 270 vertex if it belongs to the classes C2. ii or C3.
3. A grid point is edge point (180 vertex) if belongs to the class C2.i.
4. A grid point is a interior point if it belongs to class C4 .








<h5>6.4. Step involved in construction of the outer cover:</h5>

1. Determination of the starting point.
    
2. Tracing the polygon:
      
       During the traversal of the polygon the direction dc from the current grid point qc (ic,jc) is know and from this we determine the next direction of traversal dn and  the next grid point qn (in,jn) from the following relationships:
 
dc = 0:   in = ic + g,   jn  = jc
dc = 1:   in = ic ,   jn  = jc  + g
dc = 2:   in = ic - g,   jn  = jc
dc = 3:   in = ic ,   jn  = jc - g

which is expressed in a simpler way as:  (in,jn) = dc ○(ic,jc).
the vertex type tn is computed by determining the object occupancy of the neighbouring UGBs. The direction of traversal dn  from qn  is given by
 dn = (dc + tn) mod 4.
Iteratively, the details of each grid point lying on P(S) are computed
until qn coincides with qs. If the grid point is a vertex, then it
is added to the sequence of vertices comprising P(S).


<h5>6.5 Algorithm:</h5>

  
Step 1: Start from the starting vertex.
   
Step 2: Initially assume d = 2
 
Step 3: find the occupancy t

Step 4: Compute  the value of d using: dn = (dc + tn) mod 4.

Step 5: Move to the next vertex, computed from the values of d and g (shown earlier).
         
Step 6: Join the initial vertex to the next vertex.

Step 7: The new vertex becomes the next vertex.

Step 8: Check if new vertex = starting vertex.

Step 9: if the result of Step 8 is false, go to Step 3.

Step 10: if if result of step 8 is true,the outer cover is completed.
       
       
<h4>7. Construction of the Inner cover:</h4>

The inner iosthetic cover (IIC) can be constructed in a manner exactly converse to that of OIC. 

<h5>7.1. Classification of vertices:</h5>

  If m (0<m<4) denotes the total number of UGBs intersected by S then q belongs to class  Class  and  corresponds to 90o and 270O vertices. Points in  and in  lie respectively inside and outside of the IIC.

<h5>7.2. Determinaiton of the starting vertex</h5>


1. Traverse image from top to bottom,from left to right.

2. Taking each point,we observe the conditions of its    containing cells. if 1 cell is uncovered and the remaining 3 are covered, the first such point becomes the starting vertex

<h5>7.3. Algorithm:</h5>
  

Step 1 : start from starting vertex 

Step 2 : initial d is determined by the position of the unoccupied cell

Step 3 : .find occupancy t

Step 4 : .compute  the value of d using: dn = (dc + tn) mod 4

Step 5 : move in the direction ,according to d, g units to get the new vertex.
Step 6 : join the initial and new vertex

Step 7 : the new vertex becomes the initial vertex

Step 8 : check if the new vertex=starting vertex

Step 9 : if result of step 8 is false, go to step 3
.
Step 10 : if result of step 8 is true,the inner cover is completed

   
       

<h4>8. Construction of the convex hull</h4>

<h5>8.1 Determination of the starting vertex</h5>
The starting vertex of outer cover is the starting vertex of the convex hull

<h5>8.2 Algorithm</h5>
Step 1 : start from starting vertex 
Step 2 : push vertex into a stack

Step 3 : if the stack has more than or equal to 5 elements,pop the top 4 elements

Step 4 : if the popped 2nd,3rd,4th and 5th elements are 1,3,3,1 or 3,3,3,1 respectively,add and/or remove vertices to remove concavity
Step 5 : push the new set of vertices into the stack

Step 6 : go to step 3

Step 7 : push 2 vertices to the stack

Step 8 : .join the vertices

Step 9 : check if stack is empty

Step 10 : if result of step 9 is false,go to step 7

Step 11 : if result of step 9 is true,the convex hull is completed


<h4>9. Observation and Results</h4>

The proposed algorithm has been implemented in C on PGM images. The program has been tested on variou PGM images with various grid sizes, some of them are  shown below.

<h4>10.Conclusion</h4>

According to the problem statement we have shown how the minimum (maximum) area (inner) outer isothetic polygon has been constructed corresponding to a grid entered by the user.
The algorithm used here does not require any backtracking, hence is an efficient algorithm. The time complexity is linear on the length of perimeter of the polygon.
Several open problems may arise in context to an isothetic cover of a digital object. It is evident that such a cover of a digital object depends on how the object is positioned or oriented with respect to the underlying grid. A challenging problem is, therefore, finding the object-grid registration for which the complexity of an isothetic cover is minimum. The complexity measure may be in terms of the number of vertices, or the perimeter, or the area of the isothetic cover. Another interesting problem is, given a collection of isothetic covers corresponding to different positions or orientations of the object for a grid size, to design an algorithm to (approximately) reconstruct the original object. The algorithm can be extended to higher dimensions for modeling 3D objects. Also, the algorithm when extended to the background of non uniform grid for higher dimensions can be useful in determining theupper and lower approximations in rough sets.



<h4>11. Shortcomings</h4>

1. P5(raw) type PGM image could not be processed.
2. Covers cannot be generated for multiple objects in the same image file.
3. The adjustment factor in noise elimination algorithm is different for different images.

<h4>12.  Applications</h4>

VLSI layout design, robot grasping and navigation, rough sets, inner and outer approximations of polytopes [3], and document image analysis. In VLSI layout design, computation of a minimum-area safety region, referred as the classical safety zone problem [1], may be necessary to ensure the correctness of design rules before fabricating an integrated circuit. The trade-off lies between the minimization of total area of the fabricated parts (an obvious economic constraint) and the necessary electrical relationship (insulation or contact) in the presence of possible production fluctuations.
In robotics, identification of free configuration space (path-planner) is a pertinent problem in robot navigation. For example, a real-time robot motion planner often uses standard graphics hardware to rasterize the configuration space into a series of bitmap slices, and then applies a dynamic programming technique to calculate paths in this rasterized space.
Deriving the electronic version of a paper document for the purpose of storage, retrieval, and interpretation, requires an efficient representation scheme. A document representation involves the steps of skew detection, page segmentation, geometric layout analysis, and logical layout analysis, for which isothetic polygons can be used. For example, in the page segmentation method [4], a document page image is cut into polygonal blocks using the inter-column and the interparagraph gaps as horizontal and vertical lines, followed by the construction of simple isothetic polygonal blocks using an intersection table. Isothetic polygons can also be used for ground truthing of complex documents.
Some other typical applications involving orthogonal hulls are analysis of landmark data, shape analysis and classification, measuring the polygonal entropy, and many such areas of computer vision and pattern recognition [7, 8, 9, 10]. Orthogonal convex polygons also find use in models of polymers, cell growth, and percolation [10]. In discrete tomography, the reconstruction of discrete sets is done using the concept of hv-convex discrete sets [4]. A properly definedconvex polygon describing a real or a digital object is often considered to be the domain of interest of the underlying object. As a result, the subject has received a considerable attention amongst researchers.


<h4>13. Refrences</h4>

[1] S.C. Nandy, B.B. Bhattacharya, A. Barrera, Safety zone problem, J. Algorithms 37 (2000) 538–569.
[2] F. Preparata, M. Shamos, Computational Geometry, Springer-Verlag, New York, 1985.
[3] A. Bemporad, C. Filippi, F.D. Torrisi, Inner and outer approximations of polytopes using boxes, Comput. Geom. Theory Appl. 27 (2004) 151–178.
[4] O.T. Akindele, A. Belaid, Page segmentation by segment tracing, in: Proceedings of the International Conference Document Analysis and Recognition (ICDAR), 1933, pp. 341–344.
[5]  A. Biswas, P. Bhowmick, B.B. Bhattacharya, Construction of isothetic covers of a digital object: A combinatorial approach Vis. Commun. Image R. 21 (2010) 295–310

[6]    A. Biswas, P. Bhowmick, B.B. Bhattacharya, Linear-time Combinatorial Algorithm to Find the Orthogonal Hull of an Object, ntl. Workshop on Combinatorial ImagAnalysis (IWCIA), volume 4958 of LNCS. Springer-Verlag, Berlin Heidelberg.    

[7]  F. Bookstein. Morphometric Tools for Landmark Data: Geometry and Biology. Cambridge Univ. Press, 1991.
[8] L. d. F. Costa and J. R. M. Cesar. Shape Analysis and Classification. CRC Press, 2001.
[9] S. T. Hyde, S. Andersson, Z. Blum, S. Lidin, K. Larsson, T. Landh, and B. W. Ninham. The Language of Shape. Elsevier, 1997.     
[10] A. F. Pitty. Geomorphology. Blackwell, 1984.                         
