public class towerPole {
    private poleNode poleHead;

    private char poleName;
    private int nodeCount;

    public towerPole(int nodeCount, boolean empty, char name) {
        this.setNodeCount(nodeCount);
        this.setPoleName(name);
        setPoleHead(new poleNode());
        poleNode currNode = this.getPoleHead();
        if (!empty) {
            for (int i = 1; i <= this.getNodeCount(); ++i) {
                currNode.setValue(i);
                if (i == this.getNodeCount())
                    currNode.setNextNode(null);
                else {
                    currNode.setNextNode(new poleNode());
                    currNode = currNode.getNextNode();
                }
            }
        } else {
            for (int i = 1; i <= this.getNodeCount(); ++i) {
                currNode.setValue(-1);
                if (i == this.getNodeCount())
                    currNode.setNextNode(null);
                else {
                    currNode.setNextNode(new poleNode());
                    currNode = currNode.getNextNode();
                }
            }
        }
    }

    boolean reallocatePole(towerPole newPole) {
        poleNode currNode = this.getPoleHead();
        poleNode newPoleNode = newPole.getPoleHead();
        poleNode newPoleNodeCopy = newPole.getPoleHead();
        int key, testKey;

        while (currNode != null) {
            newPoleNodeCopy = newPole.getPoleHead();
            testKey = -1;
            key = currNode.getValue();
            while (newPoleNodeCopy != null) {
                if (newPoleNodeCopy.getValue() != -1) {
                    testKey = newPoleNodeCopy.getValue();
                    break;
                }
                newPoleNodeCopy = newPoleNodeCopy.getNextNode();
            }
            if (key != -1 && (testKey > key || testKey == -1)) {
                newPoleNode.setValue(key);
                currNode.setValue(-1);
                return true;
            }
            currNode = currNode.getNextNode();
            newPoleNode = newPoleNode.getNextNode();
        }
        return false;
    }

    public void recusiveDel(poleNode currentNode) {
        if (currentNode != null)
            recusiveDel(currentNode.getNextNode());
        currentNode = null;
    }

    public int getNodeCount() {
        return this.nodeCount;
    }

    public void setNodeCount(int nodeCount) {
        this.nodeCount = nodeCount;
    }

    public char getPoleName() {
        return this.poleName;
    }

    public void setPoleName(char poleName) {
        this.poleName = poleName;
    }

    public poleNode getPoleHead() {
        return this.poleHead;
    }

    public void setPoleHead(poleNode poleHead) {
        this.poleHead = poleHead;
    }

}
