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

class ParamEvalMethod: public Base {
    
};

class ParamEvalMethodFactory: public Base {

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
    LinearModel();
    ~LinearModel();
    bool setInputSize(size_t _inputDim);
    bool setInput(std::vector<double>& _input, size_t _inputDim);
    bool setOutputSize(size_t _outputDim);
    bool setOutput(std::vector<double>& _output, size_t _outputDim);
    bool setParams(std::vector<double>& _params, size_t _paramDim); // can use to set or initialize params
    std::vector<double>& computeOutput(); // compute the output with params and input given
    bool evaluateParams(size_t numData, std::vector<std::vector<double>>& _inputs, size_t _inputDim, std::vector<std::vector<double>>& _outputs, size_t _outputDim); // evaluate the params with a list of sample input and output
    bool updateParam(std::vector<double>& _input, size_t _inputDim, std::vector<double>& _output, size_t _outputDim); // update params with given new data
protected:
    size_t mInputSize = 1;
    std::vector<double> mInput; // the input list
    size_t mOutputSize = 1;
    std::vector<output> mOutput;
    std::vector<double> mParams;
};

class StatModelFactory: public Base {
public: 
    StatModelFactory() = default;
    ~StatModelFactory() {}
    StatModel createModel(std::string& name) {
        switch (mSupportedModel(name)) {
            case 1:
                return LinearModel();
            default:
                return LinearModel();
        }
    }
protected:
    const std::map<std::string, int> mSupportedModel;
};

SAIL_NAMESPACE_END


#endif // SAIL_MATH_STATISTIC_H_
