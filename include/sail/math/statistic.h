#pragma once
#ifndef SAIL_MATH_STATISTIC_H_
#define SAIL_MATH_STATISTIC_H_

/**
 * @file: include/math/statistic.h
 * @author: sailing-innocent
 * @create: 2022-11-01
 * @desp: The Statistic Method Header. all of the statistic part will use double as precision
*/

#include <sail/math.h>
#include <map>

SAIL_NAMESPACE_BEGIN

class StatData: public Base {
public:
    StatData() = default;
    ~StatData() {}
};


class StatModel: public Base {
public:
    StatModel() = default;
    ~StatModel() {}
};

/**
 * @class LinearModel
 * [output] = [params][input]
*/
class LinearModel: public StatModel {
public:
    LinearModel(size_t _inputDim = 1, size_t _outputDim = 1):
        mInputDim(_inputDim),
        mInput(VectorXd(_inputDim)),
        mOutputDim(_outputDim),
        mOutput(VectorXd(_outputDim)),
        mParam(MatrixXd(_inputDim, _outputDim))
    {}
    ~LinearModel() {}
    size_t& inputDim() { return mInputDim; }
    VectorXd& input() { return mInput; }
    bool setInputDim(size_t _inputDim) { mInputDim = _inputDim; return true; }
    bool setInput(std::vector<double>& _input, size_t _inputDim) {
        setInputDim(_inputDim);
        for (auto i = 0; i < _inputDim; i++) {
            mInput(i) = _input[i];
        }
        return true;
    }
    const size_t outputDim() const { return mOutputDim; }
    const VectorXd& output() const { return mOutput; }
    bool setOutputDim(size_t _outputDim) { mOutputDim = _outputDim; return true; }
    bool setOutput(std::vector<double>& _output, size_t _outputDim) {
        setOutputDim(_outputDim);
        for (auto i = 0; i < _outputDim; i++) {
            mOutput(i) = _output[i];
        }
        return true;
    }
protected:
    size_t mInputDim = 1;
    VectorXd mInput;
    size_t mOutputDim = 1;
    VectorXd mOutput;
    MatrixXd mParam;
};

class StatModelFactory: public Base {
public: 
    StatModelFactory() = default;
    ~StatModelFactory() {}
    StatModel createModel(std::string& name) {
        switch (mSupportedModel.at(name)) {
            case 1:
                return LinearModel();
            default:
                return LinearModel();
        }
    }
protected:
    const std::map<std::string, int> mSupportedModel = {
        {"linear", 1}
    };
};

SAIL_NAMESPACE_END


#endif // SAIL_MATH_STATISTIC_H_
