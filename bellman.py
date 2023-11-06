Source Code:
class Bellman:
    def __init__(self,vertices):
    self.V = vertices
    self.graph = []
    
    def addEdge(self,u,v,w):
    self.graph.append([u, v, w])
    
    def printArr(self,src,dist):
    print(&quot;Vertex Distance from&quot;,src)
    for i in range(self.V):
    print(&quot;{} \t\t {}&quot;.format(i, dist[i]))
         
    def BellmanFord(self, src):
    dist = [float(&quot;Inf&quot;)] * self.V
    dist[src] = 0
    for i in range(self.V - 1):
    for u, v, w in self.graph:
    if (dist[u] != float(&quot;Inf&quot;) and dist[u] + w &lt; dist[v]):
    dist[v] = dist[u] + w
    for u, v, w in self.graph:
    if(dist[u] != float(&quot;Inf&quot;) and dist[u] + w &lt; dist[v]):
    print(&quot;Graph contains negative weight cycle&quot;)
    return
    self.printArr(src,dist)
vert = int(input(&quot;Enter no. of vertices:&quot;))
edge = int(input(&quot;Enter no. of edges:&quot;))
g = Bellman(vert)
print(&quot;Enter edge1 edge2 and weight of each edge:&quot;)
for count in range(edge):
    u = int(input(&quot;1st:&quot;))
    v = int(input(&quot;2nd:&quot;))
    w = int(input(&quot;weight:&quot;))
    g.addEdge(u,v,w)
start = int(input(&quot;Enter starting vertex:&quot;))    
g.BellmanFord(start)


