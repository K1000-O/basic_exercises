package system;

public class System_ {
    private System_ instance = null;

    private System_() {

    }

    public System_ getInstance() {
        if (instance == null) instance = new System_();

        return instance;
    }
}