# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if (not root):
            return ""

        queue = [root]
        res = ""

        while (queue != []):
            q = queue[0]
            queue.pop(0)

            if (q):
                res = res + str(q.val) + ","

            else:
                res = res + "null,"

            if (q):
                queue.append(q.left)
                queue.append(q.right)
        print(res)
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if (data == ""):
            return None

        vals = data.split(",")
        root = TreeNode(int(vals[0]))
        i = 1
        tree = [root]

        while (len(tree) != 0):
            if (vals[i] != "null"):
                tree[0].left = TreeNode(vals[i])
                i+= 1
                tree.append(tree[0].left)
                
            else:
                tree[0].left = None
                i+=1
                
            if (vals[i] != "null"):
                tree[0].right = TreeNode(vals[i])
                i+= 1
                tree.append(tree[0].right)
                
            else:
                tree[0].right = None
                i+=1
               
            tree.pop(0) 
            
        return root
    