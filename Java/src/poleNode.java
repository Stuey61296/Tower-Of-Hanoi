public class poleNode {

    private int value;
    private poleNode nextNode;

    public poleNode(){
        System.out.println("New PoleNode Created");
    }

    public void setNextNode(poleNode nextNode){
        this.nextNode = nextNode;
    }

    public poleNode getNextNode(){
        return this.nextNode;
    }

    public void setValue(int value){
        this.value = value;
    }

    public int getValue(){
        return this.value;
    }
}
