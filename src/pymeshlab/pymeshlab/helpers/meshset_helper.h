/****************************************************************************
* PyMeshLab                                                         o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005-2021                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#ifndef PYMESHLAB_MESHSET_HELPER_H
#define PYMESHLAB_MESHSET_HELPER_H

#include <string>
#include <QString>
#include <QAction>

class RichParameterList;
class MeshDocument;
class MeshModel;
class RasterModel;
class FilterPlugin;
class FilterScript;
class QGLWidget;

namespace pybind11 {
class kwargs;
class dict;
}

namespace pymeshlab {

class Function;
class FunctionSet;
class MeshSet;

namespace meshsethelper {

/** RichParameterList Management **/

void updateRichParameterList(
		const std::string& filtername,
		const RichParameterList& base,
		RichParameterList& toUpdate);

void updateRichParameterListFromKwargs(
		const Function& f,
		const pybind11::kwargs& kwargs,
		MeshDocument* md,
		RichParameterList& rps,
		bool ignoreFileName = false);

pybind11::dict pydictFromRichParameterList(
		const RichParameterList& rps);

/** QVariant map management **/

pybind11::dict toPyDict(const std::map<std::string, QVariant>& qVariantMap);

/** Filter name management **/

FilterPlugin* pluginFromFilterName(
		const QString& filterName,
		QAction*& action);

bool pythonFilterNameExists(
		const std::string& filtername, 
		const FunctionSet& filterFunctionSet);

/** Load/Save Mesh **/

void loadMeshUsingPlugin(
		const std::string& filename,
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FunctionSet& filterFunctionSet);

void loadRasterUsingPlugin(
		const std::string& filename,
		MeshDocument& md);

void saveMeshUsingPlugin(
		const std::string& filename,
		MeshModel* mm,
		bool saveTextures,
		int qualityTextures,
		pybind11::kwargs kwargs,
		MeshDocument& md,
		const FunctionSet& filterFunctionSet);

/** Load/Save Project **/

void loadALN(
		const QString& fileName, 
		MeshDocument& md);

void loadMLP(
		const QString& fileName,
		MeshDocument& md);

void loadBundler(
		const QString& fileName,
		MeshDocument& md);

void loadNVM(
		const QString& fileName,
		MeshDocument& md);

void saveMLP(
		const QString& fileName,
		MeshDocument& md);

/** OpenGL context **/

//void initOpenGLContext(QAction* action, FilterPluginInterface* fp, QGLWidget*& wid, MeshSet& ms);
//void releaseOpenGLContext(FilterPluginInterface* fp, QGLWidget*& wid);

/** Apply Filter **/

pybind11::dict applyFilterRPL(
		const std::string& filtername,
		const QString& meshlabFilterName,
		QAction* action,
		FilterPlugin* fp,
		const RichParameterList& rpl,
		bool verbose,
		FilterScript& filterScript,
		bool updateFilterScript,
		MeshSet& md);

} //namespace pymeshlab::meshset_helper
} //namespace pymeshlab


#endif // PYMESHLAB_MESHSET_HELPER_H
