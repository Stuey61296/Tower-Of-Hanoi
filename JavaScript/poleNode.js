class PoleNode {
  constructor() {
    this.value = 0;
  }

  getValue = () => {
    return this.value;
  };

  setValue = (value) => {
    this.value = value;
  };
}

exports.PoleNode = PoleNode;
